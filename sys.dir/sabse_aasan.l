%%
((((a|b)*(c|d)*)+)|(ab*c*d))[[:space:]] {printf("Valid");return 0;}
(((0|1))|(0*1))[[:space:]] {printf("Valid");return 0;}
(((01*2)|(0*2+1))+)[[:space:]] {printf("Valid");return 0;}
. {printf("Invalid"); return 0;}
%%

int yywrap() {}
int main() {
yylex();
return 0;
}
