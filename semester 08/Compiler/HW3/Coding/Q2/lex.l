/*** Definition section ***/
%option noyywrap
%{
    
    #include "parser.tab.h"
    #include <stdio.h>
    #include <string>
    using namespace std;
%}

%option yylineno



DIGIT [0-9]
CHAR [a-zA-Z]

%%
"int"       return INT;
"bool"      return BOOL;
"if"        return IF;
"else"      return ELSE;
"while"     return WHILE;
"true"      return TRUE;
"false"     return FALSE;
"||"        return OR;
"&&"        return AND;
"="         return ASSIGN;
"=="        return EQ;
"!="        return NEQ;
"<="        return LTE;
">="        return GTE;
"<"         return LT;
">"         return GT;
"+"         return PLUS;
"-"         return MINUS;
"*"         return TIMES;
"/"         return DIVIDE;
"!"         return NOT;
"("         return LPAREN;
")"         return RPAREN; 
"{"         return LBRACE; 
"}"         return RBRACE;
";"         return SEMICOLON;
","         return COMMA;
{DIGIT}+                                {yylval.ival = atoi (yytext); return INT_LITERAL;}
{CHAR}({CHAR}|{DIGIT})*        {yylval.var = new string(yytext); return IDENTIFIER;}
.   {}
\n {}
%%

