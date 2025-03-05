/*** Definition section ***/
%option noyywrap
%{
    #include <stdio.h>
    #include <iostream>
    #include <string>
    #include "parser.tab.h"
    #define error 256
    int yyerror(char const *);
%}


%%

"bool" return BOOLEAN;
"float" return FLOAT;
"int" return INT;
"if" return IF;
"else" return ELSE;
"while" return WHILE;
"true" return TRUE;
"false" return FALSE;
"<=" return LE_OP;
">=" return GE_OP;
"==" return EQ_OP;
"!=" return NE_OP;
"&&" return AND_OP;
"||" return OR_OP;
"(" return LPARENT;
")" return RPARENT;
"{" return LBRACE;
"}" return RBRACE;
";" return SEMICOLON;
"," return COMMA;
"=" return ASSIGN_OP;
"*" return MULT_OP;
"/" return DIVIDE_OP;
"-" return SUB_OP;
"+" return ADD_OP;
"%" return MOD_OP;
"<" return LESS_OP;
">" return GREAT_OP;
"&" return ANDB_OP;
"|" return ORB_OP;
"^" return XOR_OP;
"!" return NOT_OP;
"~" return NOTB_OP;
[a-zA-Z_][0-9a-zA-Z_]* return VARIABLE;
[0-9]+\.[0-9]+ return FLOATLITERAL;
\.[0-9]+ return FLOATLITERAL;
[0-9]+\. return FLOATLITERAL;
[0-9]+ return INEGERLITERAL;
" " {;}
"\t" {;}
%%
