%{
	#include <stdio.h>
	int word_count = 0, char_count = 0, line_count = 0, comment_count = 0;
%}
%%
[^ \t\n]+ {word_count += 1; char_count += yyleng;} /* If whitespace or tab or newline is not found, it should be word. character count should increase by the length of the word that is obtained*/
\n {line_count +=1;}
"/*".*"*/" | 
"//".* {comment_count +=1;}
%%
main(){
	yyin = fopen("sample.txt","r");
	yyout = fopen("output.txt","w");
	yylex();
	fprintf(yyout,"\nWord Count is : %d\n",word_count);
	fprintf(yyout,"\nCharacter Count is: %d\n",char_count);
	fprintf(yyout,"\nNewline Count is: %d\n",line_count);
	fprintf(yyout,"\nComment Count is: %d\n",comment_count);
	fclose(yyin);
	fclose(yyout);
}