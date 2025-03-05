#include <iostream>
#include <sstream>
#include <stack>
#include <vector>
#include <math.h>

using namespace std;

class Converter{
public:
    Converter() = default;
    void calculate(){
        if(isdigit(input[ input.length()-2 ]))
            prefix();
        else
            postfix();
    }
    friend istream& operator>>(istream & in, Converter & _o);
    friend ostream& operator<<(ostream & out, Converter & _o);
    void setInput(string & s){
        input=s;
    }

private:
    long result=0;
    stack<int> _stack;
    string input;

    void postfix(){
        string parsed;
        std::stringstream input_stringstream(input);

        while (getline(input_stringstream,parsed,' ')){
            if(isdigit(parsed[0]) || parsed.length()>1)
                _stack.push(atoi(parsed.c_str()));
            else{
                int d2=_stack.top();
                _stack.pop();
                int d1=_stack.top();
                _stack.pop();
                _stack.push(calValue(d1,d2, parsed[0]));
            }
        }
        result=_stack.top();
    }

    void prefix(){
        string parsed;
        std::stringstream input_stringstream(input);
        vector<string> container;
        while (getline(input_stringstream,parsed,' ')){
            container.push_back(parsed);
        }
        for(int i=container.size()-1;i>=0;i--){
            parsed=container[i];
            if(isdigit(parsed[0]) || parsed.length()>1)
                _stack.push(atoi(parsed.c_str()));
            else{
                int d1=_stack.top();
                _stack.pop();
                int d2=_stack.top();
                _stack.pop();
                _stack.push(calValue(d1,d2, parsed[0]));
            }
        }

        result=_stack.top();
    }

    int calValue(int d1,int d2,char c){
        switch(c){
        case '-':
            return d1-d2;
        case '+':
            return d1+d2;
        case '*':
            return d1*d2;
        case '/':
            return floor(d1/d2);
        case '^':
            return pow(d1,d2);
        }
    }

};

ostream & operator<<(ostream & out, Converter & _o){
    out << _o.result;
    return out;
}

int main()
{
    Converter c;
    int n=0;
    cin >>n;
    string ch;
    string s;
    for(int i=0;i<n;i++){
        cin >> ch;
        s+=ch+' ';
    }
    c.setInput(s);
    c.calculate();
    cout << c;
    return 0;
}
