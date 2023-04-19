#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+10;
const int N=1e3;
int dist[N][N];

void floyed_warshal(int n,int e)
{
    int i,j,k;
    

    for(k=1;k<=n;k++){
        for(i=1;i<=n;i++){
            for(j=1;j<=n;j++){
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
}

int main()
{
    int i,j,k,u,v,w,n,e;

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i==j){
                dist[i][j]=0;
            }
            else{
                dist[i][j]=INF;
            }
        }
    }

    cin>>n>>e;

    for(i=1;i<=e;i++){
        cin>>u>>v>>w;
        dist[u][v]=w;
        dist[v][u]=w;
    }

    floyed_warshal(n,e);


    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            printf("Distance form node %d to %d----->%d\n",i,j,dist[i][j]);
        }
    }
}
