#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
vector<int>graph[N];
bool visited[N];
int level[N];

void bfs(int source)
{
    queue<int>q;
    q.push(source);
    visited[source]=1;
    level[source]=0;
    while(!q.empty()){
        int cur_ver=q.front();
        q.pop();

        for(int child: graph[cur_ver]){
            if(!visited[child]){
                q.push(child);
                visited[child]=1;
                level[child]=level[cur_ver]+1;
            }
        }

    }
}
int main()
{
    int n,m,n1,n2,i;
    cout<<"Enter number of node and and edge: ";
    cin>>n>>m;

    for(i=0;i<m;i++){
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    cout<<"Enter source node : ";
    cin>>n1;

    bfs(n1);
    cout<<endl<<endl;
    for(i=0;i<n;i++){
        cout<<"Node "<<i<<"----->"<<level[i]<<endl;

    }
    /*
7 8
0 1
0 2
1 2
1 3
2 4
2 5
3 4
5 6
0
*/

}

