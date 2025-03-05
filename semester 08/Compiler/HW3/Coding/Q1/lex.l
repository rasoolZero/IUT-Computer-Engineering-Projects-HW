/*** Definition section ***/
%option noyywrap
%{
    #include <stdio.h>
    #include <iostream>
    #include <string>
    #include "parser.tab.h"
    #define error 256
    void yyerror(char const *);
%}

%option yylineno
DIGIT [0-9]
VALID [a-zA-Z_][a-zA-Z0-9_]*

%%
"sin"                           {return SIN;}
"cos"                           {return COS;}
"tan"                           {return TAN;}
"cot"                           {return COT;}
"log"                           {return LOG;}
"exp"                           {return EXP;}
"print"                         {return PRINT;}
({DIGIT}*[.])?{DIGIT}+         {yylval.fval = atof (yytext); return NUMBER;}
{VALID}          {yylval.var = strdup(yytext); return VAR;}

{DIGIT}{VALID}     {
    std::string errorstr = "invalid variable name : " + std::string(yytext);
    yyerror(errorstr.c_str());
    return error;
    }

[ \t]                           {;}
\n                              {return NEWLINE;}
"="                             {return ASSIGN;}
"+"                             {return ADD;}
"-"                             {return SUBTRACT;}
"*"                             {return MULTIPLY;}
"/"                             {return DIVIDE;}
"^"                             {return POWER;}
"("                             {return LPAR;}
")"                             {return RPAR;}
.                               {
    std::string errorstr = "invalid character : " + std::string(yytext);
    yyerror(errorstr.c_str());
    }
%%

