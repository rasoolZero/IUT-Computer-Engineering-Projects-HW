/*** Definition section ***/
%option noyywrap
%{
    #include <stdio.h>
%}

/*** Rules section ***/
%%
(\ ) printf("Token_Space ");
\n printf("Token_Newline ");
[bgmpv]et printf("Token_xet ");
\/\/.*\n printf("Token_Commnet ");
[0-9]+ printf("Token_Integer ");
[0-9]+\.[0-9]+ printf("Token_Float ");
\"[^\"]*\" printf("Token_String ");
[a-z]+([0-9]|[a-z])* printf("ID_Token ");
%%

/*** C Code section ***/
int main(void)
{
    FILE * inputF = fopen("input.txt","r");
    if(!inputF){
        puts("tried to open input.txt, failed. please provide input.txt");
        system("PAUSE");
        return 1;
    }
    yyin = inputF;
    yylex();
    system("PAUSE");
    return 0;
}