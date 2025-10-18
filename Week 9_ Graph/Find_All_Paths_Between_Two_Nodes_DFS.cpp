#include <iostream>
using namespace std;

int adj[10][10], n;
bool visited[10];

void printPath(int path[], int pathLen){
    for(int i=0;i<pathLen;i++) cout << path[i] << " ";
    cout << endl;
}

void DFS(int u, int end, int path[], int pathLen){
    visited[u] = true;
    path[pathLen] = u;
    pathLen++;

    if(u == end) printPath(path, pathLen);
    else{
        for(int v=1; v<=n; v++){
            if(adj[u][v] && !visited[v])
                DFS(v, end, path, pathLen);
        }
    }
    visited[u] = false; // backtrack
}

int main(){
    int e, start, end;
    cin >> n >> e;
    for(int i=0;i<e;i++){
        int u,v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected
    }
    cin >> start >> end;

    for(int i=1;i<=n;i++) visited[i] = false;
    int path[10];
    cout << "All paths from " << start << " to " << end << ":\n";
    DFS(start, end, path, 0);
}
