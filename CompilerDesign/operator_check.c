/*
@author 	: SRvSaha
TimeStamp	: 04:27 PM 24-03-2017
Description	: Expt 6 || To design a lexical analyser which can check whether an entry is operator or not
*/

// Code to check whether an entry is an operator or not
#include <stdio.h>
#include <string.h>
int main()
{
	char entry[5];
	scanf("%s",entry);
	switch(entry[0]){
		case '+':
			// && && strlen(entry) == 2 is required otherwise +++ will also
			// be regarded as increment operator
			if(entry[1] == '+' && strlen(entry) == 2)
				printf("Increment operator\n");
			else if(entry[1] == '=' && strlen(entry) == 2)
				printf("Assignment by Addition operator\n");
			// This is the case when only = is to be termed as addition operator.
			// Else =! will also be treated as addition operator
			else if (strlen(entry) == 1)
				printf("Addition operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '-':
			if(entry[1] == '-' && strlen(entry) == 2)
				printf("Decrement operator\n");
			else if(entry[1] == '=' && strlen(entry) == 2)
				printf("Assignment by Subtraction operator\n");
			else if (strlen(entry) == 1)
				printf("Subtraction operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '*':
			if(entry[1] == '=' && strlen(entry) == 2)
				printf("Assignment by Multiplication operator\n");
			else if (strlen(entry) == 1)
				printf("Multiplication operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '/':
			if(entry[1] == '=' && strlen(entry) == 2)
				printf("Assignment by Division operator\n");
			else if (strlen(entry) == 1)
				printf("Division operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '%':
			if(entry[1] == '=' && strlen(entry) == 2)
				printf("Assignment by Modulus operator\n");
			else if (strlen(entry) == 1)
				printf("Modulus operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '=':
			if(entry[1] == '=' && strlen(entry) == 2)
				printf("Equality check operator\n");
			else if (strlen(entry) == 1)
				printf("Assignment operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '!':
			if(entry[1] == '=' && strlen(entry) == 2)
				printf("NOT-EQUAL operator\n");
			else if (strlen(entry) == 1)
				printf("Logical NOT operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '>':
			if(entry[1] == '>'){
				if(entry[2] == '=' && strlen(entry) == 3)
					printf("Right Shift and Assignment operator\n");
				else if (strlen(entry) == 2)
					printf("Binary Right Shift operator\n");
				else 
					printf("Not an operator\n");
			}
			else if(entry[1] == '=' && strlen(entry) == 2){
				printf("GREATER_THAN_OR_EQUAL operator\n");
			}
			else if (strlen(entry) == 1)
				printf("GREATER_THAN operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '<':
			if(entry[1] == '<'){
				if(entry[2] == '=' && strlen(entry) == 3)
					printf("Left Shift and Assignment operator\n");
				else if (strlen(entry) == 2)
					printf("Binary Left Shift operator\n");
				else 
					printf("Not an operator\n");
			}
			else if(entry[1] == '=' && strlen(entry) == 2){
				printf("LESS_THAN_OR_EQUAL operator\n");
			}
			else if (strlen(entry) == 1)
				printf("LESS_THAN operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '&':
			if(entry[1] == '&' && strlen(entry) == 2)
				printf("Logical AND operator\n");
			else if(entry[1] == '=' && strlen(entry) == 2)
				printf("Bitwise AND Assignment operator\n");
			else if (strlen(entry) == 1)
				printf("Bitwise AND operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '|':
			if(entry[1] == '|' && strlen(entry) == 2)
				printf("Logical OR operator\n");
			else if(entry[1] == '=' && strlen(entry) == 2)
				printf("Bitwise Inclusive OR Assignment operator\n");
			else if (strlen(entry) == 1)
				printf("Bitwise OR operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '^':
			if(entry[1] == '=' && strlen(entry) == 2)
				printf("Bitwise Exclusive OR Assignment operator\n");
			else if (strlen(entry) == 1)
				printf("Bitwise XOR operator\n");
			else 
				printf("Not an operator\n");
			break;
		case '~':
			if(strlen(entry) == 1)
				printf("Binary Ones Complement operator\n");
			else
				printf("Not an operator\n");
			break;
		default:
			printf("Not an operator\n");
	}	
	return 0;
}
