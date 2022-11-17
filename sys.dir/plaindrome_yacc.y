%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
extern yylex();
void yyerror(char *msg);
int flag;
int i;
int k=0;
%}

%union{
char* f;
}

%token <f> STR
%type <f> E

%%

S: E{
flag=0;
k=strlen($1) -1;
int cntc=0;
if (k%2==0){
	for (i=0;i<=k;i++){
		if ($1[i]==$1[k-i]){}
		else flag=1;
		if ($1[i]=='c') cntc++;
	}
}
k++;
if ($1[k/2]!='c'||flag==1||k%2==0) printf("Not Palindrome!");
else if (cntc!=1) printf("Not Palindrome!");
else printf("Palindrome");
}
;

E: STR {$$=$1;}
%%

void yyerror(char *msg){
fprintf(stderr, "%s\n", msg);
exit(1);
}

int main(){
yyparse();
return 0;
}
