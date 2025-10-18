#include <iostream>
using namespace std;

int adj[10][10], n;
bool visited[10];

int edgeCount;

void DFS(int u){
    visited[u] = true;
    for(int v=1; v<=n; v++){
        if(adj[u][v]){
            edgeCount++;
            if(!visited[v])
                DFS(v);
        }
    }
}

int main(){
    int e; cin >> n >> e;
    for(int i=0;i<e;i++){
        int u,v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=1;i<=n;i++) visited[i]=false;

    int components=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            edgeCount=0;
            DFS(i);
            components++;
            cout << "Component " << components << " has " << edgeCount/2 << " edges\n";
        }
    }
}
