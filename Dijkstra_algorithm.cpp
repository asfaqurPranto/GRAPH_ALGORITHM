/*
6 9
0 1 1
0 2 5
1 3 2
1 4 1
1 2 2
2 4 2
3 5 1
3 4 3
4 5 2
0
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int INF=1e9+10,visited[N]={0};
int dist[N];
vector<pair<int,int>>graph[N];

void dijkstra(int source)
{
    set<pair<int,int>>st;  //which will work as sortrd in queue (wt,node);
    for(int i=0;i<N;i++){
        dist[i]=INF;
    }
    st.insert({0,source});
    dist[source]=0;


    while(!st.empty()){
        auto node=*st.begin();
        int v=node.second;
        int wt=node.first;
        st.erase(st.begin());
        if(!visited[v]){
            for(auto child: graph[v]){
                int child_wt=child.first;
                int child_v=child.second;

                if(dist[v]+child_wt<dist[child_v]){
                    dist[child_v]=dist[v]+child_wt;

                    st.insert({dist[child_v],child_v});
                }
            }
            visited[v]=1;
        }

    }
}

int main()
{
    int n,m,n1,n2,wt,i,source;
    cout<<"Enter number of node and edge: ";
    cin>>n>>m;
    cout<<"Enter edge and weight:\n";
    for(i=0;i<m;i++){
        cin>>n1>>n2>>wt;
        graph[n1].push_back({wt,n2});
    }

    cout<<"Enter source node : ";
    cin>>source;


    dijkstra(source);

    for(i=0;i<n;i++){
        printf("sortest distance of node %d form %d ------->%d\n",i,source,dist[i]);
    }

}
