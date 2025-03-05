%{
    #define YYDEBUG 1
    #include <stdio.h>
    #include <iostream>
    #include <cmath>
    #include <string>
    extern int yylex();
    extern int yylineno;
    extern FILE* yyin;
    int isPrefix;
    int yyerror(char const *);

    void debugger(const char * s, float v1,float v2){
        printf("%s : %f , %f\n",s,v1,v2);
    }
%}

%union{
    float ival;
}

%token <ival> NUMBER
%token <ival> MULTIPLY DIVIDE SUBTRACT POWER ADD
%start program
%define parse.error custom

%type <ival> Epre Epost Fpost Fpre N postfix prefix

%locations

%left ADD SUBTRACT
%left MULTIPLY DIVIDE
%right POWER

%%

program : 
    {printf("## prefix\n");} prefix  
    | {printf("## postfix\n");}  postfix 
    | error {yyerror("Syntax error"); return 1;}
prefix : Epre
Epre : ADD Fpre Fpre | SUBTRACT Fpre Fpre | MULTIPLY Fpre Fpre | DIVIDE Fpre Fpre | POWER Fpre Fpre 
Fpre : Epre | N  

postfix : Epost
Epost : Fpost Fpost ADD | Fpost Fpost SUBTRACT | Fpost Fpost MULTIPLY | Fpost Fpost DIVIDE | Fpost Fpost POWER 
Fpost : Epost | N 

N : 
    NUMBER


%%

int yyreport_syntax_error (const yypcontext_t *yyctx){
    return 0;
}
int yyerror (char const *msg) {
    return printf("error: %s\n", msg);
}

int main(int argc, const char * argv[]){
    /* yydebug= 1; */
    if(argc < 2){
        puts("usage: parser.exe path_to_inputfile");
        puts("terminating");
        return 0;
    }
    else{
        FILE* file = fopen(argv[1],"r");
        if(!file){
            printf("could not open file '%s'.");
            return 1;
        }
        yyin = file;
    }
    yyparse();
}
