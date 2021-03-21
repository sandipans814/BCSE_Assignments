%{
	#include<stdio.h>
	#include<string.h>
	int integers = 0,floats = 0;
%}
%%
([0-9])+[ \n\t] {integers++;}
([0-9])+[.][ \n\t] {integers++;}
([0-9])+[.][(0-9)]+[ \n\t] {floats++;}
[a-zA-Z0-9]*[ \n\t]
%%
int yywrap(void){
	return 1;
}
int main(int argc, char*argv[]){
	extern FILE *yyin;
	/*if(argc>=2)
		yyin = fopen(argv[1],"r");
	else
		yyin = fopen("Input.txt", "r"); */
	yylex();
    printf("Number of integers = %d\nNumber of floats = %d\n",integers,floats);
}