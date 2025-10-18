#include <iostream>
using namespace std;

int main() {
    int n, e;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> e;

    int adj[10][10] = {0}; // max 10 nodes

    cout << "Enter edges (u v):\n";
    for(int i=0;i<e;i++){
        int u,v;
        cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1; // undirected graph
    }

    cout << "Adjacency Matrix:\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cout << adj[i][j] << " ";
        cout << endl;
    }
    return 0;
}
