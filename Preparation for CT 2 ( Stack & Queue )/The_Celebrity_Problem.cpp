// Given a square matrix mat[][] of size n x n, where mat[i][j] == 1 means person i knows person j, and mat[i][j] == 0 means person i does not know person j, find the celebrity person where,

// A celebrity is defined as someone who:

// Is known by everyone else
// Does not know anyone (except themselves)
// Return the index of the celebrity if one exists, otherwise return -1.

// Note: It is guaranteed that mat[i][i] == 1 for all i

// Examples:  

// Input: mat[][] = [[1, 1, 0], 
//                              [0, 1, 0], 
//                              [0, 1, 1]]
// Output: 1
// Explanation: 0th and 2nd person both know 1. Therefore, 1 is the celebrity.

// Input: mat[][] = [[1, 1], 
//                              [1, 1]]
// Output: -1
// Explanation: The two people at the party both know each other. None of them is a celebrity.

// Input: mat[][] = [[1]]
// Output: 0

#include <bits/stdc++.h>
using namespace std;

int findCelebrity(int mat[][100], int n) 
{
    int candidate = 0;
    for (int i = 1; i < n; i++) 
    {
        if (mat[candidate][i] == 1) 
        {
            candidate = i;
        }
    }

    for (int i = 0; i < n; i++) 
    {
        if (i == candidate) continue;

        if (mat[candidate][i] == 1 || mat[i][candidate] == 0) 
        {
            return -1;
        }
    }

    return candidate;
}

int main() 
{
    int n;
    int mat[100][100];

    cout << "Enter the number of people: ";
    cin >> n;

    cout << "Enter the matrix (" << n << "  " << n << "):" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> mat[i][j];
        }
    }

    int celeb = findCelebrity(mat, n);

    if (celeb == -1)
        cout << "No celebrity found!" << endl;
    else
        cout << "Celebrity is person: " << celeb << endl;

    return 0;
}
