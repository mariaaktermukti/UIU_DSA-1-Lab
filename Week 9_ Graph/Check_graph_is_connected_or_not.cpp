#include <iostream>
using namespace std;

const int MAX = 100; // max nodes
int graph[MAX][MAX]; // adjacency matrix
bool visited[MAX];
int n, e;

void DFS(int node)
{
    visited[node] = true;
    for (int i = 0; i < n; i++)
    {
        if (graph[node][i] == 1 && !visited[i])
        {
            DFS(i);
        }
    }
}

int main()
{
    cout << "Enter number of nodes: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;

    // initialize graph and visited array
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        for (int j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    cout << "Enter edges (u v) zero-indexed:\n";
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u][v] = 1;
        graph[v][u] = 1; // because undirected
    }

    DFS(0); // start DFS from node 0

    bool connected = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            connected = false;
            break;
        }
    }

    if (connected)
        cout << "Graph is connected\n";
    else
        cout << "Graph is not connected\n";

    return 0;
}
