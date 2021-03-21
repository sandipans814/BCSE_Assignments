%{
	#include<stdio.h>
	#include<string.h>
	int words = 0;
%}
%%
[aeiouAEIOU]([a-zA-Z0-9])*[ \n\t] {words++;}
([a-zA-Z0-9])*[ \n\t]
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
    printf("Number of words that start with a vowel = %d\n",words);
}