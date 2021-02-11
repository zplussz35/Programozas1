  
%{
#include <stdio.h>	
int mgho= 0;
%}
mgh [a,e,i,o,u]
%%
mgh { 	mgho++;
	printf("%s", yytext);}
.   {}
%%
int main(){
	yylex();
	printf("maganhangzok szama: %d\n", mgho);
	return 0;
}