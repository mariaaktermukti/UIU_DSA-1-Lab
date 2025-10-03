#include <iostream>
using namespace std;

// Structure to represent a cell in BFS
struct Node
{
    int pos;  // Current cell number (0-based)
    int dist; // Number of dice throws to reach this cell
};

// Simple array-based queue to perform BFS
struct Queue
{
    Node arr[1000];  // Array to store queue elements (adjust size if needed)
    int front, rear; // Front and rear indices of the queue

    Queue()
    {
        front = 0;
        rear = 0;
    }

    void push(Node x) { arr[rear++] = x; } // Add element to queue
    Node pop() { return arr[front++]; }    // Remove element from queue
    bool empty() { return front == rear; } // Check if queue is empty
};

// Function to find minimum dice throws to reach last cell
int minDiceThrows(int board[], int n)
{
    bool visited[1000] = {false}; // Keep track of visited cells
    Queue q;                      // Queue for BFS

    q.push({0, 0});    // Start from first cell (0 index) with 0 dice throws
    visited[0] = true; // Mark first cell as visited

    while (!q.empty())
    {
        Node curr = q.pop(); // Get front element

        // If we reached the last cell, return the number of dice throws
        if (curr.pos == n - 1)
            return curr.dist;

        // Try all possible dice throws from 1 to 6
        for (int dice = 1; dice <= 6; dice++)
        {
            int next = curr.pos + dice; // Next cell after dice throw

            // Check if next cell is within board and not visited
            if (next < n && !visited[next])
            {
                visited[next] = true; // Mark cell as visited

                // If there is a snake or ladder at next cell, move to final position
                int finalPos = (board[next] != -1) ? board[next] : next;

                // Push new node into queue with incremented dice count
                q.push({finalPos, curr.dist + 1});
            }
        }
    }

    return -1; // Should not happen if board is valid
}

int main()
{
    int n;
    cout << "Enter total number of cells: ";
    cin >> n;

    int board[1000]; // Array to store board info
    for (int i = 0; i < n; i++)
        board[i] = -1; // -1 means normal cell (no snake or ladder)

    int ladders;
    cout << "Enter number of ladders: ";
    cin >> ladders;
    cout << "Enter ladder positions (start end):\n";
    for (int i = 0; i < ladders; i++)
    {
        int start, end;
        cin >> start >> end;
        board[start - 1] = end - 1; // Convert to 0-based index
    }

    int snakes;
    cout << "Enter number of snakes: ";
    cin >> snakes;
    cout << "Enter snake positions (start end):\n";
    for (int i = 0; i < snakes; i++)
    {
        int start, end;
        cin >> start >> end;
        board[start - 1] = end - 1; // Convert to 0-based index
    }

    int minThrows = minDiceThrows(board, n); // Call BFS function
    cout << "Minimum number of dice throws: " << minThrows << endl;

    return 0;
}
