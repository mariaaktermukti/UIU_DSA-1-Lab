// Given an integer n, Generate the binary representations of all numbers from 1 to n.

// Examples: 

// Input: n = 4
// Output: [1, 10, 11, 100]
// Explanation:
// Binary representation of 1 → 1
// Binary representation of 2 → 10
// Binary representation of 3 → 11
// Binary representation of 4 → 100

// Input: n = 6
// Output: [1, 10, 11, 100, 101, 110]
// Explanation:
// Binary representation of 1 → 1
// Binary representation of 2 → 10
// Binary representation of 3 → 11
// Binary representation of 4 → 100
// Binary representation of 5 → 101
// Binary representation of 6 → 110

#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    queue<string> q;
    q.push("1");

    cout << "Binary representations from 1 to " << n << ":\n";

    for (int i = 0; i < n; i++) {
        string s = q.front();
        q.pop();

        // Print directly instead of storing in vector
        cout << s << " ";

        // Generate next binary numbers
        q.push(s + "0");
        q.push(s + "1");
    }

    cout << endl;
    return 0;
}
