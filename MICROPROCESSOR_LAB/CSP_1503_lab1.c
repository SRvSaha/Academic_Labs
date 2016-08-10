#include <stdio.h>
#include <math.h> // for pow
#include <string.h> // for strlen
#include <stdlib.h> // For atoi
char* strrev(char* str) // Since strrev is not present as a part of standard C, so gcc doesn't have it, so manually written it
{
    int i = 0;
    static char result[100];
    int len = strlen(str);
    for(; i < len; i++){
        result[i] = str[len-1 - i];
    }
    result[i] = '\0';
    return result;
}
long long binary_to_decimal(char num[],int size)
{
	long res = 0;
	int i = 0;
	int temp;
	for(; i < size; i++){
		temp = num[i] - '0';
		res += temp*pow(2,size-1-i);
	}
	return res;
}
long long decimal_to_binary(int num)
{
	char temp[100];
	int i = 0;
	long long res;
	while(num != 0){
		temp[i] = num % 2 + '0';
		num /= 2;
		i++;
	}
	temp[i] = '\0';
	res = atoi(strrev(temp));
	return res;
}
long long binary_to_octal(char num[],int size)
{
	int res = binary_to_decimal(num,size);
	char temp[100];
	int i = 0;
	long long result;
	while(res != 0){
		temp[i++] = res % 8 + '0';
		res /= 8;
	}
	temp[i] = '\0';
	result = atoi(strrev(temp));
	return result;
}
long long octal_to_binary(char num[],int size)
{
	int res = 0;
	int i = 0;
	char temp[100];
	long long result;
	for(; i < size; i++){
		int temp = num[i] - '0';
		res += temp*pow(8,size-1-i);
	}
	i = 0;
	while(res != 0){
		temp[i++] = res % 2 + '0';
		res /= 2;
	}
	temp[i] = '\0';
	result = atoi(strrev(temp));
	return result;
}
char* binary_to_hexadecimal(char num[],int size)
{
	int res = binary_to_decimal(num,size);
	char temp[100];
	static char* result; // Static is must else we cant sent the address of temp from the function as it is local to the function
	int i = 0;
	int rem;
	while(res != 0){
		rem = res % 16;
		if(rem > 9){
			switch(rem){
				case 10:
					temp[i++] = 'A';
					break;
				case 11:
					temp[i++] = 'B';
					break;
				case 12:
					temp[i++] = 'C';
					break;
				case 13:
					temp[i++] = 'D';
					break;
				case 14:
					temp[i++] = 'E';
					break;
				case 15:
					temp[i++] = 'F';
					break;
			}
		}
		else
			temp[i++] = res % 16 + '0';
		res /= 16;
	}
	temp[i] = '\0';
	result = strrev(temp);
	return result;
}
long long hexadecimal_to_binary(char num[],int size)
{
	int res = 0;
	int i = 0;
	int rem;
	for(; i < size; i++){
		rem = num[i] - '0';
		if(rem < 10)
			res += rem*pow(16,size-1-i);
		else{
			rem = num[i];
			switch(rem){
				case 'A':
					rem = 10;
					res += rem*pow(16,size-1-i);
					break;
				case 'B':
					rem = 11;
					res += rem*pow(16,size-1-i);
					break;
				case 'C':
					rem = 12;
					res += rem*pow(16,size-1-i);
					break;
				case 'D':
					rem = 13;
					res += rem*pow(16,size-1-i);
					break;
				case 'E':
					rem = 14;
					res += rem*pow(16,size-1-i);
					break;
				case 'F':
					rem = 15;
					res += rem*pow(16,size-1-i);
					break;
			}
		}
	}
	long long result = decimal_to_binary(res);
	return result;
}
int main()
{
	char num[100];
	int choice ;
	int number;
	while(1){
		printf("Enter your choice :\n1.Binary to Decimal\n2.Binary to Octal\n3.Binary to Hexadecimal\n4.Decimal to Binary\n5.Octal to Binary\n6.Hexadecimal to Binary\n7.Exit\n\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				printf("Enter the binary number: ");
                scanf("%s",num);
				printf("BINARY-to-DECIMAL is : %lld\n\n",binary_to_decimal(num,strlen(num)));
				break;
            case 2 :
                printf("Enter the binary number: ");
                scanf("%s",num);
                printf("BINARY-to-OCTAL is : %lld\n\n",binary_to_octal(num,strlen(num)));
                break;
            case 3:
                printf("Enter the binary number: ");
                scanf("%s",num);
                printf("BINARY-to-HEXADECIMAL is : %s\n\n",binary_to_hexadecimal(num,strlen(num)));
                break;
            case 4:
                printf("Enter the decimal number: ");
                scanf("%d",&number);
                printf("DECIMAL-to-BINARY is : %lld\n\n",decimal_to_binary(number));
                break;
            case 5:
                printf("Enter the octal number: ");
                scanf("%s",num);
                printf("OCTAL-to-BINARY is : %lld\n\n",octal_to_binary(num,strlen(num)));
                break;
            case 6:
                printf("Enter the hexadecimal number: ");
                scanf("%s",num);
                printf("HEXADECIMAL-to-BINARY is : %lld\n\n",hexadecimal_to_binary(num,strlen(num)));
                break;
            case 7:
                return 0;
		}
	}
	return 0;
}
