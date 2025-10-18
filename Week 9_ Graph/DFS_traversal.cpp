#include <iostream>
using namespace std;

int adj[10][10], n;
bool visited[10];

void DFS(int u){
    visited[u] = true;
    cout << u << " ";
    for(int v=1;v<=n;v++){
        if(adj[u][v] && !visited[v])
            DFS(v);
    }
}

int main(){
    int e;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int u,v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=1;i<=n;i++) visited[i] = false;

    cout << "DFS Order: ";
    DFS(1);
}
