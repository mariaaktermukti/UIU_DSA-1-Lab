// Given an array arr[], for each element, find the first element to its right that appears more times 
// in the array than the current element. If no such element exists, assign -1.

// Examples: 

// Input: arr[] = [2, 1, 1, 3, 2, 1]
// Output: [1, -1, -1, 2, 1, -1] 
// Explanation: Frequencies: 1 → 3 times, 2 → 2 times, 3 → 1 time.
//  For arr[0] = 2, the next element 1 has a higher frequency → 1.
//  For arr[1] and arr[2] (1), no element to the right has a higher frequency → -1.
//  For arr[3] = 3, the next 2 has a higher frequency → 2.
//  For arr[4] = 2, the next 1 has a higher frequency → 1.
//  For arr[5] = 1, no elements to the right → -1.

// Input: arr[] = [1, 2, 1]
// Output: [-1, 1, -1]
// Explanation: Frequencies: 1 → 2, 2 → 1.
//  2→1 (higher freq), others have no higher freq on right → [-1, 1, -1]


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int arr[1000];         // assuming n ≤ 1000
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // 1) Count frequencies (assuming values ≤ 1000)
    int freq[1001] = {0};
    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int res[1000];         // result array
    int st[1000];          // stack implemented using array
    int top = -1;          // stack pointer

    // 2) Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from stack while their frequency <= current element frequency
        while (top >= 0 && freq[arr[st[top]]] <= freq[arr[i]]) {
            top--;
        }

        // If stack is not empty, top element is the answer
        if (top >= 0) res[i] = arr[st[top]];
        else res[i] = -1;

        // Push current index into stack
        st[++top] = i;
    }

    // 3) Print the result
    for (int i = 0; i < n; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}
