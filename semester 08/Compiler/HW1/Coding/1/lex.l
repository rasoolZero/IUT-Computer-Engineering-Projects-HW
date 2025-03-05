/*** Definition section ***/
%option noyywrap
%{
    #include <stdio.h>
    const char inputfile[] = "input.txt";
    const char outputfile[] = "output.txt";
    FILE * inputF;
    FILE * outputF;
    void w(char ch){
        fputc(ch,outputF);
    }
%}

/** Rules section **/
%%
\.- {w('a');}
-\.\.\. {w('b');}
-\.-\. {w('c');}
-\.\. {w('d');}
\. {w('e');}
\.\.-\. {w('f');}
--\. {w('g');}
\.\.\.\. {w('h');}
\.\. {w('i');}
\.--- {w('j');}
-\.- {w('k');}
\.-\.\. {w('l');}
-- {w('m');}
-\. {w('n');}
--- {w('o');}
\.--\. {w('p');}
--\.- {w('q');}
\.-\. {w('r');}
\.\.\. {w('s');}
- {w('t');}
\.\.- {w('u');}
\.\.\.- {w('v');}
\.-- {w('w');}
-\.\.- {w('x');}
-\.-- {w('y');}
--\.\. {w('z');}
\/ {w(' ');}
. {;} // ignore anyother character
%%

/*** C Code section ***/
int main(void)
{
    inputF = fopen(inputfile,"r");
    if(!inputF){
        puts("tried to open input.txt, failed. please provide input.txt");
        system("PAUSE");
        return 1;
    }
    outputF = fopen(outputfile,"w");
    yyin = inputF;
    yylex();
    puts("translation is ready in output.txt");
    system("PAUSE");
    return 0;
}