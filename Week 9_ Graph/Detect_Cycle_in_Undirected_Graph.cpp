#include <iostream>
using namespace std;

int adj[10][10], n;
bool visited[10];

bool DFS(int u, int parent){
    visited[u] = true;
    for(int v=1; v<=n; v++){
        if(adj[u][v]){
            if(!visited[v]){
                if(DFS(v,u)) return true;
            } else if(v != parent){
                return true; // cycle detected
            }
        }
    }
    return false;
}

int main(){
    int e; cin >> n >> e;
    for(int i=0;i<e;i++){
        int u,v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=1;i<=n;i++) visited[i] = false;

    bool cycle = false;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            if(DFS(i, -1)) {
                cycle = true;
                break;
            }
        }
    }

    if(cycle) cout << "Graph has a cycle\n";
    else cout << "Graph has no cycle\n";
}
