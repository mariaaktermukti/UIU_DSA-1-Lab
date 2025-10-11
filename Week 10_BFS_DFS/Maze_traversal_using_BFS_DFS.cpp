// Problem 4: Maze Traversal Using BFS and DFS
// You are given a 2D grid representing a maze where each cell can be either
// free (0) or blocked (1). A robot can move up, down, left, or right from a cell.
// Use BFS to find the shortest path length from the top-left corner (0, 0) to a
// given target cell (r, c). Then, use DFS to check whether a path exists to
// another given cell (r2, c2).
// Input Format:
// - The first line contains two integers n and m (rows and columns).
// - The next n lines each contain m integers (0 or 1).
// - The last line contains two pairs of integers: (r, c) for BFS target and (r2, c2)
// for DFS target.
// Output Format:
// - Print the shortest path length from (0, 0) to (r, c) using BFS.
// - Print whether a path exists from (0, 0) to (r2, c2) using DFS.
// Example Input:
// 4 4
// 0 1 0 0
// 0 0 1 0
// 1 0 0 0
// 0 0 0 1
// 3 2 3 3
// Example Output:
// BFS shortest path length to (3,2): 6
// DFS path to (3,3): Not found

#include <bits/stdc++.h>
using namespace std;

// directions → up, down, left, right (for BFS & DFS movement)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// DFS function to check path existence
bool dfs(int x, int y, int r2, int c2, vector<vector<int>> &grid, vector<vector<bool>> &visited)
{
    int n = grid.size();    // number of rows
    int m = grid[0].size(); // number of columns

    if (x == r2 && y == c2)
        return true; // target found, return true

    visited[x][y] = true; // mark current cell as visited

    for (int dir = 0; dir < 4; dir++)
    {                         // explore 4 directions
        int nx = x + dx[dir]; // next row
        int ny = y + dy[dir]; // next column

        // check bounds, not blocked, and not visited
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && !visited[nx][ny])
        {
            if (dfs(nx, ny, r2, c2, grid, visited))
                return true; // recursive DFS
        }
    }
    return false; // no path found from this cell
}

int main()
{
    int n, m;
    cin >> n >> m; // read grid size (rows n, columns m)

    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j]; // read maze (0 = free, 1 = blocked)

    int r, c, r2, c2;
    cin >> r >> c >> r2 >> c2; // BFS target (r,c) and DFS target (r2,c2)

    // ---------- BFS for shortest path ----------
    vector<vector<int>> dist(n, vector<int>(m, -1));         // distance array (-1 = unreachable)
    vector<vector<bool>> visited(n, vector<bool>(m, false)); // visited array for BFS
    queue<pair<int, int>> q;                                 // queue for BFS

    if (grid[0][0] == 0)
    {                         // start BFS only if starting cell is free
        q.push({0, 0});       // push starting cell
        visited[0][0] = true; // mark starting cell visited
        dist[0][0] = 1;       // distance of starting cell = 1
    }

    while (!q.empty())
    {                             // BFS loop
        int x = q.front().first;  // current cell row
        int y = q.front().second; // current cell column
        q.pop();

        for (int dir = 0; dir < 4; dir++)
        { // explore 4 directions
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // if inside grid, free cell, and not visited
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && grid[nx][ny] == 0 && !visited[nx][ny])
            {
                visited[nx][ny] = true;        // mark visited
                dist[nx][ny] = dist[x][y] + 1; // distance = current + 1
                q.push({nx, ny});              // push neighbor into queue
            }
        }
    }

    // print BFS result
    if (dist[r][c] != -1)
        cout << "BFS shortest path length to (" << r << "," << c << "): " << dist[r][c] << endl;
    else
        cout << "BFS shortest path length to (" << r << "," << c << "): Not reachable" << endl;

    // ---------- DFS for path existence ----------
    visited.assign(n, vector<bool>(m, false)); // reset visited array for DFS
    bool pathExists = false;
    if (grid[0][0] == 0)
        pathExists = dfs(0, 0, r2, c2, grid, visited); // run DFS

    // print DFS result
    if (pathExists)
        cout << "DFS path to (" << r2 << "," << c2 << "): Found" << endl;
    else
        cout << "DFS path to (" << r2 << "," << c2 << "): Not found" << endl;
}
