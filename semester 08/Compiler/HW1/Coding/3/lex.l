/*** Definition section ***/
%option noyywrap
%{
    #include <stdio.h>
    typedef enum Type{
        Double,Int,Char
    }Type;

    Type currentType;
    const char * typetostr(Type type){
        if(type == Double)
            return "double";
        if(type == Int)
            return "int";
        if(type == Char)
            return "char";

    }
    void printVariable(char * variableName){
        printf("%s %s\n",variableName,typetostr(currentType));
    }
%}


/*** Rules section ***/
%%
double {currentType = Double;}
int {currentType = Int;}
char {currentType = Char;}

main {/*ignoring main*/;}
, {/*ignoring comma token*/;}
[\ \t\r\n\f]+ {/*ignoring white space tokens*/;}
= {/*ignoring assignment token*/;}
=[^,^;]*[,;] {/*ignoring assignment of variables*/;}
; {/*ignoring assignment token*/;}
#.*\n {/*ignoring preprocessing macros*/;}
([a-zA-Z\_])([a-zA-Z0-9\_])* {printVariable(yytext);}
. {/*ignoring any unrecognized character*/;}
%%

/*** C Code section ***/
int main(void)
{
    FILE * inputF = fopen("input.cpp","r");
    if(!inputF){
        puts("tried to open input.cpp, failed. please provide input.cpp");
        system("PAUSE");
        return 1;
    }
    yyin = inputF;
    yylex();
    system("PAUSE");
    return 0;
}