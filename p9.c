#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include<stdbool.h>

void DFS(int** adj,int root,int nodes,bool* visited){
	printf("%d ",root);
	if(visited[root] == true){
		return;
	}
	else{
		visited[root] = true;
		for(int i=0;i<nodes;i++){
			if(adj[root][i]==1 && !visited[i]){
				DFS(adj,i,nodes,visited);
			}
		}
	}
	return;
}

int main(){
	int nodes,edges;
	printf("Enter the number of nodes and edges : ");
	scanf("%d%d",&nodes,&edges);
	int **arr = (int**)malloc(nodes*sizeof(int*));
	for(int i=0;i<nodes;i++){
		arr[i] = (int*)malloc(nodes*sizeof(int));
	}
	memset(*arr,0,nodes*nodes*sizeof(*arr));
	for(int i=0;i<edges;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		arr[a][b] = 1;
	}
	bool visited[nodes];
	memset(visited,false,nodes*sizeof(bool));
	DFS(arr,0,nodes,visited);
}