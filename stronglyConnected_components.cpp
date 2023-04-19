#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
vector<int>graph[N],Tgraph[N],tem;
bool visited[N]={false},T_visited[N]={false};
vector<int> stk;
vector<vector<int>>strongly_connected;
void dfs(int vertex)
{

    visited[vertex]=true;
    //cout<<vertex<<"p"<<endl;
    stk.push_back(vertex);
    for(int adj:graph[vertex]){
        if(!visited[adj]){
            dfs(adj);
        }
    }

    return;
}
void dfs_transpose(int vertex)
{
    tem.push_back(vertex);
    T_visited[vertex]=true;
    for(int adjk:Tgraph[vertex]){
        if(!T_visited[adjk]){
            dfs_transpose(adjk);
        }
    }

}
int main()
{
    int n,m,n1,n2,i;
    cout<<"Enter node and edge :";
    cin>>n>>m;

    for(i=0;i<m;i++){
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        Tgraph[n2].push_back(n1);
    }

    for(i=0;i<n;i++){
        if(!visited[i]) dfs(i);
    }

    int cnt=0;

    for(i=0;i<n;i++){
        if(!T_visited[i]){
                cnt++;
            dfs_transpose(stk[i]);
            strongly_connected.push_back(tem);
            tem.clear();
        }
    }
    cout<<"\nTotal Number of strongly connected components: ";
    cout<<cnt<<endl;

    for(auto x:strongly_connected){
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }

}
/* 
5 5
0 2
0 3
1 0
2 1
3 4
*/