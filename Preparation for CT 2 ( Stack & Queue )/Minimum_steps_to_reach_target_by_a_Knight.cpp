#include <bits/stdc++.h>
using namespace std;

// Structure to store knight position and distance
struct Node
{
    int x, y, dist;
};

// Check if position is inside the chessboard
bool isInside(int x, int y, int n)
{
    return (x >= 0 && x < n && y >= 0 && y < n);
}

// Function to find minimum steps for knight to reach target
int minKnightSteps(int n, pair<int, int> start, pair<int, int> target)
{
    // All 8 possible moves of a knight
    int dx[] = {2, 2, -2, -2, 1, 1, -1, -1};
    int dy[] = {1, -1, 1, -1, 2, -2, 2, -2};

    vector<vector<bool>> visited(n, vector<bool>(n, false));

    queue<Node> q;
    q.push({start.first, start.second, 0});
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        Node curr = q.front();
        q.pop();

        // If reached target
        if (curr.x == target.first && curr.y == target.second)
            return curr.dist;

        // Check all 8 possible moves
        for (int i = 0; i < 8; i++)
        {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            if (isInside(nx, ny, n) && !visited[nx][ny])
            {
                visited[nx][ny] = true;
                q.push({nx, ny, curr.dist + 1});
            }
        }
    }

    return -1; // If target cannot be reached (should not happen in normal chessboard)
}

int main()
{
    int n;
    cout << "Enter chessboard size n: ";
    cin >> n;

    int kx, ky, tx, ty;
    cout << "Enter Knight position (row col): ";
    cin >> kx >> ky;
    cout << "Enter Target position (row col): ";
    cin >> tx >> ty;

    int steps = minKnightSteps(n, {kx, ky}, {tx, ty});
    cout << "Minimum steps: " << steps << endl;

    return 0;
}
