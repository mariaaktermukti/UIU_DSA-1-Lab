#include <iostream>
using namespace std;

int main(){
    int n,e; cin >> n >> e;
    int adj[10][10] = {0};

    for(int i=0;i<e;i++){
        int u,v; cin >> u >> v;
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    for(int i=1;i<=n;i++){
        int degree = 0;
        for(int j=1;j<=n;j++)
            degree += adj[i][j];
        cout << "Degree of node " << i << " = " << degree << endl;
    }
}
