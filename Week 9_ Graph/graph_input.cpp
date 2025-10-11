#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, E;
    cin >> N >> E; // N = number of nodes, E = number of edges

    vector<int> adj[N + 1]; // adjacency list (1-based indexing)

    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u); // undirected graph, so both sides
    }

    // Print adjacency list
    for (int i = 1; i <= N; i++)
    {
        cout << i << " -> ";
        for (int j = 0; j < adj[i].size(); j++)
        {
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}
