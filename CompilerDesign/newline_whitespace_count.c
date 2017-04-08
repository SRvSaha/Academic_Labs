/*
@author : SRvSaha
TimeStamp : 17-02-2017
Experiment No : 4 from Lab Manual || Compiler Design

Title : Whitespace and newline identification
*/
#include <stdio.h>
#include <string.h>
int main(){
	int cnt_whitespace = 0;
	int cnt_newline = 0;
	char string[100];
	scanf("%[^!]s",string); // Until ! is found we take the input in the string from the stream.
	for(int i = 0; i < strlen(string); i++){
		if(string[i] == 10) // 10 = ASCII for NEWLINE
			cnt_newline++;
		else if (string[i] == 32){ // 32 = ASCII for WHITESPACE
			cnt_whitespace++; 
		}
	}
	printf("New Lines : %d\n",cnt_newline);
	printf("White Space : %d\n",cnt_whitespace);
	return 0;
}