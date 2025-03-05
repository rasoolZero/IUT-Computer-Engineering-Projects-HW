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


%token VARIABLE BOOLEAN FLOAT INT IF ELSE WHILE 
%token INEGERLITERAL FLOATLITERAL TRUE FALSE
%token LPARENT RPARENT LBRACE RBRACE SEMICOLON COMMA
%token ASSIGN_OP MULT_OP DIVIDE_OP SUB_OP ADD_OP  MOD_OP  LESS_OP  GREAT_OP  LE_OP  GE_OP  EQ_OP  NE_OP  ANDB_OP  AND_OP  ORB_OP  OR_OP  XOR_OP NOT_OP  NOTB_OP
%start Program



%locations

%left ASSIGN_OP
%left OR_OP
%left AND_OP
%left XOR_OP
%left ORB_OP
%left ANDB_OP
%left EQ_OP NE_OP
%left LESS_OP GREAT_OP LE_OP GE_OP
%left SUB_OP ADD_OP
%left MULT_OP DIVIDE_OP MOD_OP
%right NOT_OP NOTB_OP

%%
Program : StatementList {puts("Program -> StatementList");}

StatementList : StatementList Statement {puts("StatementList -> StatementList Statement");}
              | %empty {puts("StatementList -> e");}

Statement : Declaration SEMICOLON {puts("Statement -> Declaration SEMICOLON");}
          | Assignment SEMICOLON {puts("Statement -> Assignment SEMICOLON");}
          | Conditional {puts("Statement -> Conditional");}
          | Loop {puts("Statement -> Loop");}

Declaration : DataType VariableList {puts("Declaration -> DataType VariableList");}

VariableList : VARIABLE COMMA VariableList {puts("VariableList -> VARIABLE COMMA VariableList");}
             | VARIABLE {puts("VariableList -> VARIABLE");}

DataType : BOOLEAN {puts("DataType -> BOOLEAN");}
         | INT {puts("DataType -> INT");}
         | FLOAT {puts("DataType -> FLOAT");}

Assignment : VARIABLE ASSIGN_OP RValue {puts("Assignment -> VARIABLE ASSIGN_OP RValue");}

RValue : VARIABLE ASSIGN_OP RValue {puts("RValue -> VARIABLE ASSIGN_OP RValue");}
       | Expression {puts("RValue -> Expression");}

Conditional : IfBlock ElseBlock {puts("Conditional -> IfBlock ElseBlock");}
            | IfBlock {puts("Conditional -> IfBlock");}

IfBlock : IF LPARENT Condition RPARENT LBRACE StatementList RBRACE {puts("IfBlock -> IF LPARENT Condition RPARENT LBRACE StatementList RBRACE");}

ElseBlock : ELSE LBRACE StatementList RBRACE {puts("ElseBlock -> ELSE LBRACE StatementList RBRACE");}

Loop : WHILE LPARENT Condition RPARENT LBRACE StatementList RBRACE {puts("Loop -> WHILE Condition RPARENT LBRACE StatementList RBRACE");}

Condition : Expression {puts("Condition -> Expression");}
          | Assignment {puts("Condition -> Assignment");}

Expression : Expression MULT_OP Expression {puts("Expression -> Expression MULT_OP Expression");}
           | Expression DIVIDE_OP Expression {puts("Expression -> Expression DIVIDE_OP Expression");}
           | Expression SUB_OP Expression {puts("Expression -> Expression SUB_OP Expression");}
           | Expression ADD_OP Expression {puts("Expression -> Expression ADD_OP Expression");}
           | Expression MOD_OP Expression {puts("Expression -> Expression MOD_OP Expression");}
           | Expression LESS_OP Expression {puts("Expression -> Expression LESS_OP Expression");}
           | Expression GREAT_OP Expression {puts("Expression -> Expression GREAT_OP Expression");}
           | Expression LE_OP Expression {puts("Expression -> Expression LE_OP Expression");}
           | Expression GE_OP Expression {puts("Expression -> Expression GE_OP Expression");}
           | Expression EQ_OP Expression {puts("Expression -> Expression EQ_OP Expression");}
           | Expression NE_OP Expression {puts("Expression -> Expression NE_OP Expression");}
           | Expression ANDB_OP Expression {puts("Expression -> Expression ANDB_OP Expression");}
           | Expression AND_OP Expression {puts("Expression -> Expression AND_OP Expression");}
           | Expression ORB_OP Expression {puts("Expression -> Expression ORB_OP Expression");}
           | Expression OR_OP Expression {puts("Expression -> Expression OR_OP Expression");}
           | Expression XOR_OP Expression {puts("Expression -> Expression XOR_OP Expression");}
           | NOT_OP Expression {puts("Expression -> NOT_OP Expression");}
           | NOTB_OP Expression {puts("Expression -> NOTB_OP Expression");}
           | LPARENT Expression RPARENT {puts("Expression -> LPARENT Expression RPARENT");}
           | VARIABLE {puts("Expression -> VARIABLE");}
           | Literal {puts("Expression -> Literal");}

Literal : BooleanLiteral {puts("Literal -> BooleanLiteral");}
        | INEGERLITERAL {puts("Literal -> INEGERLITERAL");}
        | FLOATLITERAL {puts("Literal -> FLOATLITERAL");}

BooleanLiteral : TRUE {puts("BooleanLiteral -> TRUE");}
               | FALSE {puts("BooleanLiteral -> FALSE");}

%%

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
