#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LEN 1000

void cyclic(char* str, int f, int r, int k){
	char substr[r-f],res[r-f];
	for(int i=0,j=f;i<=r-f,j<=r;i++,j++){
		substr[i] = str[j];
	}
	for(int i=0;i<k;i++){
		res[i] = substr[r-f-k+i+1];
	}
	for(int i=k,j=0;i<r-f,j<=k;i++,j++){
		res[i] = substr[j];
	}
	int j=0;
	for(int i=f;i<=r;i++){
		str[i] = res[j];
		j++;
	}
}

int main(int argc, char const *argv[])
{
	char str[MAX_LEN];
	gets(str);
	int m;scanf("%d",&m);
	while(m--){
		int f,r,k;
		scanf("%d %d %d",&f,&r,&k);
		cyclic(str,f,r,k);
	}
	printf("%s\n",str);
	return 0;
}