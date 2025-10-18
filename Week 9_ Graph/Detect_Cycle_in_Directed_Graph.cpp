#include <iostream>
using namespace std;

int adj[10][10], n;
bool visited[10], recStack[10];

bool DFS(int u)
{
    visited[u] = true;
    recStack[u] = true;

    for (int v = 1; v <= n; v++)
    {
        if (adj[u][v])
        {
            if (!visited[v] && DFS(v))
                return true;
            else if (recStack[v])
                return true;
        }
    }

    recStack[u] = false;
    return false;
}

int main()
{
    int e;
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u][v] = 1; // directed
    }

    for (int i = 1; i <= n; i++)
        visited[i] = recStack[i] = false;

    bool cycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && DFS(i))
        {
            cycle = true;
            break;
        }
    }

    if (cycle)
        cout << "Directed Graph has a cycle\n";
    else
        cout << "Directed Graph has no cycle\n";
}
