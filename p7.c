#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

int main(int argc, char const *argv[])
{
	char pass[MAX_STRING_LENGTH];
	char ceasar[MAX_STRING_LENGTH];
	printf("Enter the password :");
	gets(pass);
	int i;
	for(i=0;i<strlen(pass);i++){
		ceasar[i] = (char)((pass[i]+3-'a')%26+'a');
	}
	ceasar[i] = '\0';
	printf("%s\n",ceasar);
	return 0;
}