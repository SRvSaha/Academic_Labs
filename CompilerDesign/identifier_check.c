/*
@author : SRvSaha
TimeStamp : 17-02-2017
Experiment No : 5 from Lab Manual || Compiler Design

Title : Testing of valid identifier
*/
#include <stdio.h>
#include <string.h>

int main(){
	const char* keywords[32]; // When you do it like this you will allocate an array of two pointers to const char. These pointers will then be set to the addresses of the static strings "auto", "int", etc
	keywords[0] = "auto";
	keywords[1] = "int";
	keywords[2] = "double";
	keywords[3] = "struct";
	keywords[4] = "break";
	keywords[5] = "else";
	keywords[6] = "long";
	keywords[7] = "switch";
	keywords[8] = "case";
	keywords[9] = "enum";
	keywords[10] = "register";
	keywords[11] = "typedef";
	keywords[12] = "char";
	keywords[13] = "extern";
	keywords[14] = "return";
	keywords[15] = "union";
	keywords[16] = "const";
	keywords[17] = "float";
	keywords[18] = "short";
	keywords[19] = "unsigned";
	keywords[20] = "continue";
	keywords[21] = "for";
	keywords[22] = "signed";
	keywords[23] = "void";
	keywords[24] = "default";
	keywords[25] = "goto";
	keywords[26] = "sizeof";
	keywords[27] = "volatile";
	keywords[28] = "do";
	keywords[29] = "if";
	keywords[30] = "static";
	keywords[31] = "while";
	char string[32];
	int flag = 1; //  By default, we assume any input string is an Identifier
	scanf("%s",string);
	for(int i = 0; i < 32; i++){
		if((strcmp(keywords[i],string)) == 0){ // If is one of the existing keyword
			printf("Not an IDENTIFIER ! It's a KEYWORD\n");
			flag = 0; // This means input string is not a keyword
		}
	}
	if(string[0] >= 48 && string[0] <= 57){ // If it starts with digits 0-9
		printf("Not an IDENTIFIER ! Can't start with digits\n");
		flag = 0; // This means input string is not a keyword
	}
	else if((string[0] >= 65 && string[0] <= 90) || (string[0] >= 97 && string[0] <= 122) || string[0] == 95){ // If the start is a-z A-Z _
		for(int i = 1; i < strlen(string);){
			if((string[i] >= 65 && string[i] <= 90) || (string[i] >= 97 && string[i] <= 122) || (string[i] == 95) || (string[i] >= 48 && string[i] <= 57)){ 
				// If starting is valid, then check for the subsequent symbols used : a-z A-Z 0-9 _
				i++;
			}
			else{
				// When any of the special symbols are used, then it can't be an identifier
				printf("Not an IDENTIFIER ! Incorrect symbols used.\n");
				flag = 0;
				break;
			}
		}
	}
	else{
		// If it starts with any of the special symbols
		printf("Not an IDENTIFIER ! Can't start with symbols\n");
		flag = 0; // This means input string is not a keyword
	}
	if(flag) // Only when the flag is true, the enterred string is a valid identifier
		printf("It is a valid IDENTIFIER\n");
	return 0;
}