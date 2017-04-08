%{
	/*To identify the identifiers*/
%}
%%
for |
while |
int |
char |
if |
else { printf("%s : is a KEYWORD\n",yytext);}
[_]*[a-zA-Z]+[0-9]* { printf("%s : is a VARIABLE\n",yytext);}
[0-9]+[a-z]+ { printf("%s : is not an identifier\n",yytext);}
[0-9]+ { printf("%s : is a constant\n",yytext);}
["][a-zA-Z]+["] { printf("%s : is a string literal\n",yytext);}
. | \n
%%
main(){
	yylex();
}