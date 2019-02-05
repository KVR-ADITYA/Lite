#include<stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 10

int main(){
	char str[MAX_STRING_LENGTH];
	gets(str);
	int arr[26];
	memset(arr,0,26*sizeof(int));
	for(int i=0;i<strlen(str);i++){
		arr[str[i]-(int)'a']++;
	}
	int count = 0;
	for(int i=0;i<26;i++){
		if(arr[i]%2 ==1){
			count++;
		}
	}
	if(count==0 || count%2==1){
		printf("Yes");
	}
	else{
		printf("No\n");
	}
}