#include<stdio.h>
#include<string.h>
#include<limits.h>
#define N 100
#define INF 99999

int n,x,y;
int adj[N][N];
int next[N][N];


void shortestPaths(){
    int dist[n][n]; 
    // next[0][0] = -1;
    for(int i=0; i<n; i++){
        dist[i][i] = 0;
        for(int j=0; j<n; j++){
            if(adj[i][j]){ dist[i][j] = 1; next[i][j] = j;}
            else {dist[i][j] = INF; next[i][j] = -1;}
        }
    }

    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                int x = dist[i][k] + dist[k][j];
                if(dist[i][j] > ((dist[i][k]==INF || dist[k][j]==INF)?INF:x)){
                    dist[i][j] = x;
                    next[i][j] = next[i][k];
                }
            }    
        }
    }
}

void printPaths(int u, int v){
    if(next[u][v]==-1) return;
    int k = 0;
    int path[N]; memset(path, -1, sizeof(path));
    path[k++] = u;
    do{
        u = next[u][v];
        path[k++] = u;
    }while(u!=v);
    int f = 0;
    for(int i=0; i<k; i++){
        if(path[i]+1==x) f=1;
        if(f && path[i]+1==y) return; 
    }
    printf("Path (%d, %d): ", path[0]+1, v+1);
    for(int i=0; i<k; i++) printf("%d ", path[i]+1);
    printf("\n");
}

int main(){
    scanf("%d %d %d",&n,&x,&y);
    for(int i=0; i<n-1; i++){
        int a,b; scanf("%d %d", &a, &b);
        adj[a-1][b-1] = adj[b-1][a-1] = 1;
    }

    shortestPaths();

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i!=j)
            printPaths(i,j);
        }
    }


    return 0;
}