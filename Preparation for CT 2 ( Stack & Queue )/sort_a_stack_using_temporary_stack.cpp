// Given a stack of integers, sort it in ascending order using another temporary stack.

// Examples: 

// Input: [34, 3, 31, 98, 92, 23]
// Output: [3, 23, 31, 34, 92, 98]
// Explanation: After Sorting the given array it would be look like as [3, 23, 31, 34, 92, 98]

// Input: [3, 5, 1, 4, 2, 8]
// Output: [1, 2, 3, 4, 5, 8] 

#include <bits/stdc++.h>
using namespace std;

void sortStack(stack<int> &s) {
    stack<int> temp; // temporary stack

    while (!s.empty()) {
        // Pop out the top element from the original stack
        int curr = s.top();
        s.pop();

        // While temporary stack is not empty and top of temp > current
        // move elements back to original stack
        while (!temp.empty() && temp.top() > curr) {
            s.push(temp.top());
            temp.pop();
        }

        // Place current element in the correct position in temp
        temp.push(curr);
    }

    // Transfer back from temp to original stack (sorted in ascending order)
    while (!temp.empty()) {
        s.push(temp.top());
        temp.pop();
    }
}

int main() {
    int n;
    cin >> n;        // number of elements in stack
    stack<int> s;

    // Read input
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }

    // Sort the stack
    sortStack(s);

    // Print sorted stack (top to bottom)
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << "\n";

    return 0;
}
