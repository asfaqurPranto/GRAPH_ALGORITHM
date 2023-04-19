#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int parent[N];
void make(int v)
{
    parent[v]=v;
}
int find(int v)
{
    if(v==parent[v]){
        return v;
    }
    return parent[v]=find(parent[v]);    //path compression
}

void Union(int a,int b)
{
    a=find(a);
    b=find(b);
    if(a!=b){
        parent[b]=a;
    }
}


int main()
{
    int i,n,m;
    cout<<"Enter number of node and edges : ";
    cin>>n>>m;
    vector<pair<int,pair<int,int>>>edges;

    for(i=1;i<=n;i++) make(i);
    for(i=0;i<m;i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        edges.push_back({wt,{u,v}});
    }

    sort(edges.begin(),edges.end());
    int total_cost=0;
    for(auto &edge: edges){
        int wt=edge.first;
        int u=edge.second.first;
        int v=edge.second.second;

        if(find(u)!=find(v)){
            Union(u,v);
            total_cost+=wt;
        }
    }

    cout<<total_cost<<endl;
}