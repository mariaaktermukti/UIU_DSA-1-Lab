// Problem 3: Counting Connected Components (Using DFS)
// Given an undirected graph, find the total number of connected components
// using DFS traversal.
// Input Format:
// - The first line contains two integers N (number of nodes) and E (number of
// edges).
// - The next E lines each contain two integers u and v representing an
// undirected edge.
// Output Format:
// - Print the number of connected components.
// - Print the list of nodes in each component.
// Example Input:
// 6 3
// 1 2
// 3 4
// 5 6
// Example Output:
// Number of components: 3
// Component 1: 1 2
// Component 2: 3 4
// Component 3: 5 6

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, E;
    cin >> N >> E; // read number of nodes and edges

    vector<vector<int>> adj(N + 1); // adjacency list (1-based indexing)
    for (int i = 0; i < E; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v); // add edge u -> v
        adj[v].push_back(u); // add edge v -> u (undirected)
    }

    vector<bool> visited(N + 1, false); // visited array to track nodes
    vector<vector<int>> components;     // store all components

    // DFS implemented inside main using stack
    for (int i = 1; i <= N; i++)
    { // iterate over all nodes
        if (!visited[i])
        {                          // if node not visited → new component
            vector<int> component; // store nodes of this component
            stack<int> st;
            st.push(i); // start DFS from node i

            while (!st.empty())
            { // continue until stack is empty
                int node = st.top();
                st.pop(); // get current node

                if (!visited[node])
                {                              // if node not yet visited
                    visited[node] = true;      // mark as visited
                    component.push_back(node); // add node to current component

                    for (int neigh : adj[node])
                    { // iterate neighbors
                        if (!visited[neigh])
                            st.push(neigh); // push unvisited neighbors
                    }
                }
            }
            components.push_back(component); // save this component
        }
    }

    //print all components
    cout << "Number of components: " << components.size() << endl; // total components
    for (int i = 0; i < components.size(); i++)
    {
        cout << "Component " << i + 1 << ": "; // component number
        for (int node : components[i])
            cout << node << " "; // print all nodes in component
        cout << endl;
    }
}
