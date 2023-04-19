#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10;
int graph[N][N];
int dist[N];
const int INF=1e9+10;
int main()
{
    int i,j,n,u,v,e,w,k;

    cin>>n>>e;
    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                graph[i][j]=0;
            }
            else{
                graph[i][j]=INF;
            }
        }
    }

    for(i=1;i<=n;i++){
        dist[i]=INF;
    }

    //input
    for(i=1;i<=e;i++){
        cin>>u>>v>>w;
        graph[u][v]=w;
    }
    int source;
    cin>>source;
    dist[source]=0;
    //Bellman ford algortihm

    for(k=1;k<=n-1;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                if(dist[j]>dist[i]+graph[i][j]){
                    dist[j]=dist[i]+graph[i][j];
                }
            }
        }
    }

    for(i=1;i<=n;i++){
        printf("Distance form node %d to node %d----->%d\n",source,i,dist[i]);
    }

}
