#include <iostream>
using namespace std;

int adj[10][10], n;
bool visited[10];

int leafCount=0;

void DFS(int u){
    visited[u]=true;
    int children=0;
    for(int v=1;v<=n;v++){
        if(adj[u][v] && !visited[v]){
            children++;
            DFS(v);
        }
    }
    if(children==0) leafCount++;
}

int main(){
    int e; cin >> n >> e;
    for(int i=0;i<e;i++){
        int u,v; cin >> u >> v;
        adj[u][v]=adj[v][u]=1;
    }
    for(int i=1;i<=n;i++) visited[i]=false;

    DFS(1);
    cout << "Number of leaf nodes = " << leafCount << endl;
}
