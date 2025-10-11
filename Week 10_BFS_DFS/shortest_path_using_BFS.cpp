// Problem 2: Shortest Path Using BFS
// Given an unweighted, undirected graph, find the shortest path between two
// nodes using BFS traversal.
// Input Format:
// - The first line contains two integers N (number of nodes) and E (number of
// edges).
// - The next E lines each contain two integers u and v indicating an edge
// between u and v.
// - The last line contains two integers S and D — the source and destination
// nodes.
// Output Format:
// - Print the shortest path from S to D as a sequence of nodes.
// - If no path exists, print 'No path exists'.
// Example Input:
// 6 7  ///6 nodes, 7 edges
// 1 2
// 2 3
// 1 4
// 4 5
// 2 5
// 5 6
// 3 6
// 1 6  src dest
// Example Output:
// Shortest path (BFS): 1 → 2 → 5 → 6

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, E;
    cin >> N >> E; // number of nodes and edges

    vector<vector<int>> adj(N + 1); // adjacency list (1-based)

    //input edges
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // add edge u -> v
        adj[v].push_back(u); // undirected graph, so v -> u also
    }

    //sort neighbors for predictable BFS path
    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end()); // smallest neighbor visited first
    }

    int S, D;
    cin >> S >> D; // source and destination

    vector<bool> visited(N + 1, false); // track visited nodes
    vector<int> parent(N + 1, -1);      // to reconstruct path

    queue<int> q;      // queue for BFS
    q.push(S);         // start BFS from source
    visited[S] = true; // mark source visited

    //BFS
    while (!q.empty())
    {
        int node = q.front();
        q.pop(); // get current node

        if (node == D)
            break; // stop if destination reached

        for (int neigh : adj[node])
        { // visit all neighbors
            if (!visited[neigh])
            {                          // if neighbor not visited
                visited[neigh] = true; // mark visited
                parent[neigh] = node;  // store parent to reconstruct path
                q.push(neigh);         // add neighbor to queue
            }
        }
    }

    //reconstruct path
    if (!visited[D])
    {                               // destination not reached
        cout << "No path exists\n"; // print no path
    }
    else
    {
        vector<int> path;
        int curr = D;

        while (curr != -1)
        {                         // trace back from destination to source
            path.push_back(curr); // add current node to path
            curr = parent[curr];  // move to parent
        }

        reverse(path.begin(), path.end()); // reverse path to get source -> destination

        cout << "Shortest path (BFS): ";
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i]; // print each node
            if (i != path.size() - 1)
                cout << "->"; // arrow between nodes
        }
        cout << endl;
    }
}
