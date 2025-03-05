all:	
	bison -d parser.y -Wcounterexamples
	flex lex.l
	g++ parser.tab.c lex.yy.c -lm -o parser -Wno-register -DYYDEBUG=1
flex:
	flex lex.l
	g++ lex.yy.c -o lexer.exe
bison:
	bison -d parser.y
clean:
	del -r *.o *.cc *.c *.tab.* *.h *.hh