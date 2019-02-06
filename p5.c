#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void DFS(int ** adj,int i,int j,int *count,bool** visited,int n){
	visited[i][j];
	*count++;
	if(i-1>=0 && j-1>=0 && visited[i-1][j-1]){
		if(adj[i-1][j-1])
		DFS(adj,i-1,j-1,count,visited,n);
	}
	if(i-1>=0 && visited[i-1][j]){
		if(adj[i-1][j])
		DFS(adj,i-1,j,count,visited,n);
	}
	if(j-1>=0 && visited[i][j-1]){
		if(adj[i][j-1])
		DFS(adj,i,j-1,count,visited,n);
	}
	if(j+1<n && visited[i][j+1]){
		if(adj[i][j+1])
		DFS(adj,i,j+1,count,visited,n);
	}
	if(i+1<n && visited[i+1][j]){
		if(adj[i+1][j])
		DFS(adj,i+1,j,count,visited,n);
	}
	if(i-1>=0 && j+1<n&&visited[i-1][j+1]){
		if(adj[i-1][j+1])
		DFS(adj,i-1,j+1,count,visited,n);
	}
	if(i+1<n && j-1>=0&&visited[i+1][j-1]){
		if(adj[i+1][j-1])
		DFS(adj,i+1,j-1,count,visited,n);
	}
	if(i+1<n && j+1<n && visited[i+1][j+1]){
		if(adj[i+1][j+1])
		DFS(adj,i+1,j+1,count,visited,n);
	}
	
	return;
}

int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int islands[n][n];
	memset(islands,0,n*n*sizeof(int));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&islands[i][j]);
		}
	}
	bool visited[n][n];
	memset(visited,false,n*n*sizeof(bool));
	int max = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(islands[i][j] && !visited[i][j]){
				int * tempc;
				*tempc = 0;
				DFS(islands,n,i,j,tempc,visited,n);
				max = *tempc>max?*tempc:max;
			}
		}
	}
	return 0;
}