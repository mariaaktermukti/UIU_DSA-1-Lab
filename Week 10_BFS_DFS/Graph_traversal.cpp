// Problem 1: Graph Traversal
// You are given a directed graph represented using adjacency lists. Implement
// both Breadth-First Search (BFS) and Depth-First Search (DFS) traversals
// starting from a given source vertex.
// Input Format:
// - The first line contains an integer N — the number of vertices.
// - The next N lines each contain a vertex label followed by its adjacent vertices.
// - The last line contains the starting vertex.
// Output Format:
// - Print the BFS traversal order.
// - Print the DFS traversal order.
// Example Input:
// 6
// A B C
// B D E
// C F
// D
// E F
// F
// A
// Example Output:
// BFS: A B C D E F
// DFS: A B D E F C

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;     // take input: number of vertices
    cin.ignore(); // ignore newline character after N

    vector<vector<int>> adj(N); // create adjacency list (vector of vectors)

    // take adjacency list input
    for (int i = 0; i < N; i++)
    {
        string line;
        getline(cin, line);    // read full line for each vertex
        stringstream ss(line); // use stringstream to split line into parts

        char u, v;
        ss >> u;            // read the vertex name (A, B, C, ...)
        int from = u - 'A'; // convert char to number (A=0, B=1, ...)

        while (ss >> v)
        {                                 // read all adjacent vertices
            adj[from].push_back(v - 'A'); // store neighbor as number
        }
    }

    char startChar;
    cin >> startChar;
    int start = startChar - 'A'; // convert starting vertex to number

    //  BFS 
    cout << "BFS: ";
    vector<bool> visitedBFS(N, false); // track visited vertices for BFS
    queue<int> q;                      // create queue for BFS
    q.push(start);                     // start BFS from starting vertex
    visitedBFS[start] = true;          // mark start as visited

    while (!q.empty())
    {                                    // run until queue is empty
        int node = q.front();            // get the front vertex from queue
        q.pop();                         // remove it from queue
        cout << char(node + 'A') << " "; // print vertex as character

        for (int neigh : adj[node])
        { // check all neighbors
            if (!visitedBFS[neigh])
            {                             // if neighbor not visited
                visitedBFS[neigh] = true; // mark visited
                q.push(neigh);            // add to queue
            }
        }
    }
    cout << endl;

    // DFS 
    cout << "DFS: ";
    vector<bool> visitedDFS(N, false); // track visited vertices for DFS
    stack<int> st;                     // stack for iterative DFS
    st.push(start);                    // start DFS from starting vertex

    while (!st.empty())
    {                        // run until stack is empty
        int node = st.top(); // get top vertex from stack
        st.pop();            // remove it from stack

        if (!visitedDFS[node])
        {                                    // if vertex not visited
            visitedDFS[node] = true;         // mark visited
            cout << char(node + 'A') << " "; // print vertex as character
        }

        // push neighbors to stack in reverse order
        // reverse to get same order as recursive DFS
        for (int i = adj[node].size() - 1; i >= 0; i--)
        {
            int neigh = adj[node][i];
            if (!visitedDFS[neigh])
                st.push(neigh); // push unvisited neighbors
        }
    }
    cout << endl;
}
