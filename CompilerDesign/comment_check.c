/*
@author : SRvSaha
TimeStamp : 03-03-2017
Experiment No : 3 from Lab Manual || Compiler Design

Title : Checking whether a line is a comment or not
*/

#include <stdio.h>
int main(){
	printf("Enter a line : 	");
	char string[100];
	// gets(string);
	scanf("%[^\n]s",string); // Works like getline in C++ ; Until \n is found, it is taken as a string
	if(string[0] == '/' && string[1] == '/' || string[1] == '*'){
		printf("It is a comment\n");
	}
	else
		printf("Not a Comment\n");
	return 0;
}