%code requires {
    #include <string>
    using namespace std;
}

%{
    #define YYDEBUG 1
    #include <iostream>
    #include <string>
    using namespace std;
    extern int yylex ();
    extern int yylineno;
    int mode;
    extern FILE* yyin;
    void yyerror(char const *);
    
%}

%define parse.error detailed

%union{
    int ival;
    string * var;
}


%token <ival> INT_LITERAL
%token <var> IDENTIFIER
%token BOOL INT IF ELSE WHILE TRUE FALSE OR AND ASSIGN EQ NEQ LTE GTE LT GT PLUS MINUS TIMES DIVIDE NOT LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA


%left OR
%left AND
%left EQ NEQ
%left LT GT LTE GTE
%left PLUS MINUS
%left TIMES DIVIDE
%nonassoc NOT
%left UNARY_MINUS
%left LPAREN RPAREN

%start program

%locations

%type <var> type program statements statement declaration assignment conditional loop list expression literal

%%

program : statements {cout << "'program' " << *$1;}

statements: {$$ = new std::string("'statements' ");} 
| statement statements {$$ = new string ("'statements' "+*$1 + *$2);} 


statement: declaration {$$ = new string("'statement' " + *$1);}
| assignment   {$$ = new string("'statement' " + *$1);}
| conditional {$$ = new string("'statement' " + *$1);}
| loop {$$ = new string("'statement' " + *$1);}

type : INT {$$ = mode?new string("'type' INT ") : new string("'type' int ") ;} 
        | BOOL {$$ = mode?new string("'type' BOOL "):new string("'type' bool ");}

list:   IDENTIFIER COMMA list{$$ = mode?new string("'list' IDENTIFIER COMMA "+*$3):new string("'list' "+*$1+" , "+*$3);} 
        | IDENTIFIER {$$ = mode?new string("'list' IDENTIFIER "):new string("'list' "+*$1+" ");};
        
declaration :  type list SEMICOLON {$$ = new string("'declaration' " + *$1 + *$2 + (mode?"SEMICOLON ":"; "));}

assignment :    IDENTIFIER ASSIGN expression SEMICOLON {$$ = mode?new string("'assignment' IDENTIFIER ASSIGN " + *$3 + "SEMICOLON "):
                new string("'assignment' "+*$1+" = " + *$3 + "; ");}
            | type IDENTIFIER ASSIGN expression SEMICOLON {$$ = mode?new string("'assignment' "+*$1 + "IDENTIFIER ASSIGN " + *$4 + "SEMICOLON "):
            new string("'assignment' "+*$1 + *$2+" = " + *$4 + "; ");};

conditional :   IF LPAREN expression RPAREN LBRACE statements RBRACE {$$ = mode?new string("'conditional' IF LPAREN "+*$3 +"RPAREN LBRACE "+*$6+ "RBRACE "):
                new string("'conditional' if ( "+*$3 +") { "+*$6+ "} ");}
                | IF LPAREN expression RPAREN LBRACE statements RBRACE ELSE LBRACE statements RBRACE
                {$$ = mode?new string("'conditional' IF LPAREN "+*$3 +"RPAREN LBRACE "+*$6 +"RBRACE ELSE LBRACE "+*$10+"RBRACE "):
                new string("'conditional' if ( "+*$3 +") { "+*$6 +"} else { "+*$10+"} ");};

loop : WHILE LPAREN expression RPAREN LBRACE statements RBRACE
        {$$ = mode?new string("'loop' WHILE LPAREN "+*$3+ "RPAREN LBRACE "+*$6 +"RBRACE "):
        new string("'loop' while ( "+*$3+ ") { "+*$6 +"} ");};

expression : IDENTIFIER {$$ = mode?new string("'expression' IDENTIFIER "):new string("'expression' "+*$1+" ");}
| literal {$$ = new string("'expression' "+*$1);}
| expression PLUS expression {$$ = new string("'expression' "+*$1+(mode?"PLUS ":"+ ")+*$3);}
| expression MINUS expression  {$$ = new string("'expression' "+*$1+(mode?"MINUS ":"- ")+*$3);}
| expression TIMES expression  {$$ = new string("'expression' "+*$1+(mode?"TIMES ":"* ")+*$3);}
| expression DIVIDE expression  {$$ = new string("'expression' "+*$1+(mode?"DIVIDE ":"/ ")+*$3);}
| expression LT expression  {$$ = new string("'expression' "+*$1+(mode?"LT ":"< ")+*$3);}
| expression GT expression  {$$ = new string("'expression' "+*$1+(mode?"GT ":"> ")+*$3);}
| expression LTE expression  {$$ = new string("'expression' "+*$1+(mode?"LTE ":"<= ")+*$3);}
| expression GTE expression  {$$ = new string("'expression' "+*$1+(mode?"GTE ":">= ")+*$3);}
| expression EQ expression  {$$ = new string("'expression' "+*$1+(mode?"EQ ":"== ")+*$3);}
| expression NEQ expression  {$$ = new string("'expression' "+*$1+(mode?"NEQ ":"!= ")+*$3);}
| expression AND expression  {$$ = new string("'expression' "+*$1+(mode?"AND ":"&& ")+*$3);}
| expression OR expression  {$$ = new string("'expression' "+*$1+(mode?"OR ":"|| ")+*$3);}
| NOT expression {$$ = new string((mode?"'expression' NOT ":"'expression' ! ")+*$2);}
| LPAREN expression RPAREN {$$ = mode?new string("'expression' LPAREN "+*$2+"RPAREN "):
                            new string("'expression' ( "+*$2+") ");}
| MINUS expression %prec UNARY_MINUS {$$ = new string((mode?"'expression' MINUS ":"'expression' - ")+*$2);}

literal : TRUE {$$ = new string(mode?"'literal' TRUE ":"'literal' true ");}
| FALSE {$$ = new string(mode?"'literal' FALSE ":"'literal' false ");}
| INT_LITERAL {$$ = new string(mode?"'literal' INT_LITERAL ":"'literal' "+std::to_string($1)+" ");}

%%


int main(int argc, char ** argv) {
    yydebug  = 0;

    if(argc < 3){
        puts("usage: parser.exe input.txt 0|1");
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
        mode = atoi(argv[2]);
        if(mode != 0 && mode != 1){
            puts("mode should be either 0 or 1");
            return 1;
        }
        
    }
    while(yyparse());
    return 0;
}

void yyerror(const char* message) {
    puts(message);
    return;
}