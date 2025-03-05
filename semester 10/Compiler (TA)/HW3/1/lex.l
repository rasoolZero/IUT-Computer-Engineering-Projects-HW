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

"+" {return ADD;}
"-" {return SUBTRACT;}
"*" {return MULTIPLY;}
"/" {return DIVIDE;}
"^" {return POWER;}
[0-9]*\.[0-9]+ {yylval.ival = atof(yytext); return NUMBER;}
[0-9]+ {yylval.ival = atoi(yytext); return NUMBER;}
" " {;}
.  {
    std::string errorstr = "invalid character : " + std::string(yytext);
    yyerror(errorstr.c_str());
    }
%%
