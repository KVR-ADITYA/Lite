#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

void checkCorrect(bool* ans,bool* visited,int t,int destination){
	if(visited[destination]){
		ans[t] = true;
	}
	else{
		ans[t] = false;
	}
	return;
}

void DFS(int** adj,int root,int nodes,bool* visited){
	visited[root] = true;
	for(int i=0;i<nodes;i++){
		if(adj[root][i] && !visited[i]){
			DFS(adj,i,nodes,visited);
		}
	}
	return;
}

int main(int argc, char const *argv[])
{
	int ** adj;
	int n,m;
	scanf("%d%d",&n,&m);
	adj = (int**) malloc(n*sizeof(int*));
	for(int i=0;i<n;i++){
		adj[i] = (int *)malloc(n*sizeof(int));
	}
	memset(*adj,0,n*n*sizeof(int));

	for(int i=0;i<m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a-1][b-1] = 1;
	}

	int t;
	int at;
	scanf("%d",&t);
	at = t;
	bool *ans = (bool *)malloc(t*sizeof(bool));
	memset(ans,false,n*sizeof(bool));

	while(t--){
		int x,y;
		scanf("%d%d",&x, &y);
		x--;y--;
		bool* visited;
		visited = (bool*)malloc(n*sizeof(bool));
		memset(visited,false,n*sizeof(bool));
		DFS(adj,x,n,visited);
		checkCorrect(ans,visited,t,y);
	}

	for(int i=at-1;i>=0;i--){
		printf("%s\n",ans[i]?"Yes":"No");
	}
	return 0;
}