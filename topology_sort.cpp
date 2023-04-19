#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>graph[N];
bool visited[N];
stack<int> stk;

void dfs(int vertex)
{
    visited[vertex]=true;
    //cout<<vertex<<endl;
    for(int adj:graph[vertex]){
        if(!visited[adj]){
            dfs(adj);
        }
    }
    stk.push(vertex);
    return;
}
int main()
{
    int n,m,n1,n2,i;
    cout<<"Enter number of node and edge :";
    cin>>n>>m;

    for(i=0;i<m;i++){
        cin>>n1>>n2;
        graph[n1].push_back(n2);
    }

    for(i=0;i<n;i++){
        if(!visited[i]) dfs(i);
    }
    cout<<"Topological sort: ";
    while(!stk.empty()){
        cout<<stk.top()<<" ";
        stk.pop();
        
    }

}
/*
6 6
2 3
3 1
4 0
4 1
5 0
5 2
*/