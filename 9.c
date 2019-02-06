#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int n,m,t;
int adj[1000][1000];
int visited[1000];

bool CheckallVisited(){
    for(int i=0;i<n;i++){
        if(visited[i]==0){
        	memset(visited,false,1000*sizeof(int));
            return false;
        }
    }
    memset(visited,false,1000*sizeof(int));
    return true;
}

void dfs(int x){
    //printf("%d\n", root);
    visited[x]=1;
    // if(x == y) return 1;
    for(int i=0;i<n;i++){
        if(!visited[i] && adj[x][i])
            dfs(i);
        }
    return ;
}

int main(int argc, char const *argv[])
{
    scanf("%d %d",&n,&m);
    
    for(int i=0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        adj[x-1][y-1] = 1;
    }
    int flag = 0;
    for(int i =0;i<n;i++){
    	dfs(i);
    	if(CheckallVisited()){
    		if(flag == 0){
    			printf("Yes\n");
    			flag++;
    		}
    		printf("%d\n",i+1);
    	}
    }
    if(flag == 0){
    	printf("No\n");
    }
    return 0;
}