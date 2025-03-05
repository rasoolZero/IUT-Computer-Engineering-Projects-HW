%{
    #define YYDEBUG 1
    #include <stdio.h>
    #include <cmath>
    #include <iostream>
    #include <string>
    #include <map>
    extern int yylex();
    extern int yylineno;
    extern FILE* yyin;
    void yyerror(char const *);
    std::map<std::string,float> table;
    void add_variable(std::string ,float);
    float lookup_variable(std::string);
    
%}


%union{
    float fval;
    char * var;
}
%token <fval> NUMBER
%token <var> VAR 
%token LPAR RPAR MULTIPLY DIVIDE SUBTRACT POWER ADD ASSIGN NEWLINE
%token PRINT COS SIN COT TAN LOG EXP
%start program
%define parse.error custom
%type <fval> expr 

%locations

%right NEWLINE
%left ADD SUBTRACT
%left MULTIPLY DIVIDE
%right POWER
%nonassoc UNARY_SUBTRACT
%left LPAR RPAR

%%

program :
    lines ;

line:
    VAR ASSIGN expr {add_variable($1,$3);free($1);}
    | PRINT LPAR expr RPAR  {printf("%f\n",$3);}
    | NEWLINE
    | error {yyerror("Syntax error"); return 1;}
lines:
    line lines | ;
expr:
    expr DIVIDE expr {
        if($3 == 0){
            yyerror("Division by zero");
            return 1;
        }
        else 
            $$ = $1 / $3;}
    | LPAR expr RPAR {$$ = $2;}
    | expr MULTIPLY expr {$$ = $1 * $3;}
    | expr SUBTRACT expr {$$ = $1 - $3;}
    | expr ADD expr {$$ = $1 + $3;}
    | expr POWER expr {$$ = powf($1,$3);}
    | SUBTRACT expr %prec UNARY_SUBTRACT {$$ = - $2;}
    | NUMBER {$$ = $1;}
    | VAR {
        try{
            $$ = lookup_variable($1);
        }
        catch(std::exception & e){
            std::string errorStr = "variable '" + std::string($1) + "' is not defined";
            yyerror(errorStr.c_str());
            free($1);
            return 1;
        }
        free($1);}
    | COT LPAR expr RPAR{ $$ = 1.f / tanf($3);}
    | TAN LPAR expr RPAR{ $$ = tanf($3);}
    | COS LPAR expr RPAR{ $$ = cosf($3);}
    | SIN LPAR expr RPAR{ $$ = sinf($3);}
    | EXP LPAR expr RPAR{ $$ = expf($3);}
    | LOG LPAR expr RPAR{ $$ = logf($3);}
    | error {yyerror("Syntax error"); return 1;}
    

%%


void add_variable(std::string key,float value){
    table[key] = value;
}
float lookup_variable(std::string key){
    if(table.find(key) == table.end())
        throw std::exception();
    return table[key];
}

void yyerror(const char* message) {
    static int skipLine = 0;
    if(message == "Syntax error"){
        if(skipLine != yylineno){
            printf("Error at line %d: %s .\n", yylineno, message);
            skipLine = 0;
        }
    }else{
        printf("Error at line %d: %s .\n", yylineno, message);
        skipLine = yylineno;
    }
}
int yyreport_syntax_error (const yypcontext_t *yyctx){
    return 0;
}

int main(int argc, char ** argv) {
    yydebug  = 0;

    if(argc < 2){
        puts("usage: parser.exe input.txt");
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
    while(yyparse());
    return 0;
}