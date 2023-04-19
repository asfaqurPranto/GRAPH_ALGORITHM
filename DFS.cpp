#include<bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2
const int N=1e5+10;
int colour[N]={WHITE},discovery[N],finishing[N],Time=1;
vector<int>graph[N];

void DFS_Visit(int source){

    colour[source]=GRAY;
    discovery[source]=Time;
    Time++;

    for(int child:graph[source]){
        if(colour[child]==WHITE){
            DFS_Visit(child);
        }
    }
    
    finishing[source]=Time;
    Time++;
    colour[source]=BLACK;
    
}

void DFS(int n)
{
    int i;
    for(int i=0;i<n;i++){
        colour[i]=WHITE;
    }
    for(i=0;i<n;i++){
        if(colour[i]==WHITE){
            DFS_Visit(i);
        }
    }
}
int main()
{
    int n,m,i,j,n1,n2;

    cout<<"Enter number of Node and edge: ";
    cin>>n>>m;
    cout<<"Enter edges: ";
    for(i=1;i<=m;i++){
        cin>>n1>>n2;
        graph[n1].push_back(n2);
    }

    DFS(n);

    for(i=0;i<n;i++){
        printf("For node %d -------->Discover time %d and finishing time %d\n",i,discovery[i],finishing[i]);
    }

}