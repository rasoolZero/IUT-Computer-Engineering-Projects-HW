#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

struct Cell{
    string label;
    string address;
    string instruction;
    string Hex;
};
std::ostream& operator << (std::ostream &o,const Cell & cell){
    o << cell.label << '\t' << cell.address << '\t' << cell.instruction << '\t' << cell.Hex;
    return o;
}


vector<Cell> compiled;
vector<Cell> temp;

int HEX2DEC(string _hex){
    stringstream ss(_hex);
    int result;
    ss >> std::hex >> result;
    return result;
}

string DEC2HEX(int _dec){
    stringstream ss;
    ss<< std::hex << _dec;
    string res ( ss.str() );
    return res;
}

int STR2DEC(string _dec){
    stringstream geek(_dec);
    int result;
    geek >> result;
    return result;
}

bool isMRI(string line){
    return  line.find("AND")==0 || line.find("ADD")==0 ||
            line.find("LDA")==0 || line.find("STA")==0 ||
            line.find("BUN")==0 || line.find("BSA")==0 ||
            line.find("ISZ")==0 ;
}
string nonMRI(string line,int lineCounter){
    if(line.find("CLA")==0)
        return "7800";
    if(line.find("CLE")==0)
        return "7400";
    if(line.find("CMA")==0)
        return "7200";
    if(line.find("CME")==0)
        return "7100";
    if(line.find("CIR")==0)
        return "7080";
    if(line.find("CIL")==0)
        return "7040";
    if(line.find("INC")==0)
        return "7020";
    if(line.find("SPA")==0)
        return "7010";
    if(line.find("SNA")==0)
        return "7008";
    if(line.find("SZA")==0)
        return "7004";
    if(line.find("SZE")==0)
        return "7002";
    if(line.find("HLT")==0)
        return "7001";
    if(line.find("INP")==0)
        return "F800";
    if(line.find("OUT")==0)
        return "F400";
    if(line.find("SKI")==0)
        return "F200";
    if(line.find("SKO")==0)
        return "F100";
    if(line.find("ION")==0)
        return "F080";
    if(line.find("IOF")==0)
        return "F040";

    throw runtime_error(string("error at line ")+string(to_string(lineCounter))+ string(" no valid instruction found"));

}

void parseMRI(int LC,int lineCounter,string line,unordered_map<string, int> &table){
    string instruction;
    string lable;
    string I;
    stringstream ss(line);
    ss >> instruction >> lable >> I;
    bool isIndirect = I=="I";
    if(table.find(lable)==table.end())
        throw runtime_error(string("error at line ")+string(to_string(lineCounter))+ string(" label ")+lable+string(" not found"));
    string value;
    string address=DEC2HEX(table[lable]);
    while(address.size()<3)
        address="0"+address;

    if(instruction=="AND")
        value=isIndirect?"8":"0";
    if(instruction=="ADD")
        value=isIndirect?"9":"1";
    if(instruction=="LDA")
        value=isIndirect?"a":"2";
    if(instruction=="STA")
        value=isIndirect?"b":"3";
    if(instruction=="BUN")
        value=isIndirect?"c":"4";
    if(instruction=="BSA")
        value=isIndirect?"d":"5";
    if(instruction=="ISZ")
        value=isIndirect?"e":"6";
    value=value+address;
    temp[LC]={"",DEC2HEX(LC),line,value};
}


unordered_map<string, int> firstPass(string code){
    unordered_map<string, int> table;
    string line;
    int LC = 0;
    int lineCounter=0;
    size_t commentPos;
    std::stringstream ss(code);
    while(getline(ss,line)){
        LC=LC%4096;
        lineCounter++;
        if((commentPos=line.find("/")) != string::npos){ //removing comment from line
            line.erase(commentPos);
        }
        while(line.find(" ") == 0){//removing space from beginning of line
            line.erase(0,1);
        }
        if(line.find(",")!=string::npos){
            string lable=line.substr(0,line.find(","));
            table.insert({lable,LC});
            LC++;
            continue;
        }
        if(line.find("ORG") == 0){
            string value=line.substr(4,string::npos);
            LC = HEX2DEC(value);
            continue;
        }
        if(line.find("END") == 0)
            break;
        else{
            LC++;
            continue;
        }
    }
    return table;
}


void secondPass(unordered_map<string, int> &table,string code){
    string line;
    int LC = 0;
    int lineCounter=0;
    size_t pos;
    std::stringstream ss(code);
    while(getline(ss,line)){
        LC=LC%4096;
        lineCounter++;
        if((pos=line.find("/")) != string::npos){ //removing comment from line
            line.erase(pos);
        }
        if((pos=line.find(",")) != string::npos){ //removing label from line
            line.erase(0,pos+1);
        }
        while(line.find(" ") == 0){//removing space from beginning of line
            line.erase(0,1);
        }
        if(line.find("ORG") == 0){
            string value=line.substr(4,string::npos);
            LC = HEX2DEC(value);
            continue;
        }
        if(line.find("DEC") == 0 || line.find("HEX") == 0){
            string numberPart=line.substr(4,string::npos);
            if(line.find("DEC") == 0){
                int value=STR2DEC(numberPart);
                numberPart=DEC2HEX(value);
            }
            else{
                int value=HEX2DEC(numberPart);
                numberPart=DEC2HEX(value);
            }
            if(numberPart.size()>4)
                numberPart=numberPart.substr(numberPart.size()-4);
            temp[LC]={"",DEC2HEX(LC),line,numberPart};
            LC++;
            continue;
        }
        if(line.find("END") == 0)
            break;
        if(isMRI(line)){
            parseMRI(LC,lineCounter,line,table);
            LC++;
        }
        else{
            string value=nonMRI(line,lineCounter);
            temp[LC]={"",DEC2HEX(LC),line,value};
            LC++;
        }

    }

}

void compiler(string code){
    size_t pos;
    //converting any "\t" to " "
    pos = code.find("\t");
    while (pos != string::npos)
    {
        code[pos]=' ';
        pos = code.find("\t");
    }
    //removing double new lines "\n\n"
    pos = code.find("\n\n");
    while (pos != string::npos)
    {
        code.erase(pos, 1);
        pos = code.find("\n\n");
    }
    //removing double spaces "  "
    pos = code.find("  ");
    while (pos != string::npos)
    {
        code.erase(pos, 1);
        pos = code.find("  ");
    }
    //converting any " ," to ","
    pos = code.find(" ,");
    while (pos != string::npos)
    {
        code.erase(pos, 1);
        pos = code.find(" ,");
    }

    unordered_map<string, int> table=firstPass(code);

    secondPass(table,code);
    for(auto pr: table){
        temp[pr.second].label=pr.first;
    }
}

