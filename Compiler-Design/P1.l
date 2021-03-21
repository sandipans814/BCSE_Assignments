 /*   lex example.l
	cc lex.yy.c -ll -o example
	./example */

%{
	#include<stdio.h>
	#include<string.h>
	int lines = 0, words = 0, charecter = 0;
%}
%%
\n {
		lines++, charecter++;
	} //counts new line and adds 1 to char bcz \n is a char
[^ \n\t]+ {words++, charecter = charecter + yyleng;} // increase word and char count until encounter \n tab or space
. {charecter++;}
%%
int yywrap(void){
	return 1;
}
int main(int argc, char*argv[]){
	extern FILE *yyin;
	if(argc>=2)
		yyin = fopen(argv[1],"r");
	else
		yyin = fopen("Input.txt", "r"); 
	yylex();
	printf("Lines = %d\nWords = %d\nCharecter = %d\n",lines,words,charecter);
}
