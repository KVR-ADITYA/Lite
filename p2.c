#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_LENGTH_OF_STRING 1000

char* substr(char* str,int start,int end){
	char substr[end-start] = "";
	int j;
	for(int i=start,j=0;i<=end;i++,j++){
		substr[j] = str[i];
	}
	return substr;
}

void cycle(char* str,int f,int r,int k){
	char one[f-r] = substr(one,str,f,r);
	char twoone[f-r-k] = substr(twoone,str,f,r-k);
	char twotwo[k] = substr(twotwo,str,r-k,r);
	char revtwotwo[k] = strrev(twotwo);
	char newone[f-r] = strcat(revtwotwo,twoone);
	strncpy(str,newone,f);
	return;
}

int main(int argc, char const *argv[])
{
	char str[MAX_LENGTH_OF_STRING];
	int m;
	gets(str);
	scanf("%d",&m);
	while(m--){
		int f,r,k;
		scanf("%d%d%d",&f,&r,&k);
		cycle(str,f,r,k);
	}
	printf("%s\n",str);
	return 0;
}