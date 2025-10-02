// Given an array of n strings arr[]. The task is to determine the number of words 
// remaining after pairwise destruction.
// If two consecutive words in the array are identical, they cancel each 
// other out. This process continues until no more eliminations are possible.

// Examples: 

// Input: arr[] = ["gfg", "for", "geeks", "geeks", "for"]
// Output: 1
// Explanation: After the first iteration, we'll have: 
// [gfg, for, for]. Then after the second iteration, we'll have: [gfg]. 
// No more eliminations are possible. Hence, the result is 1.

// Input: arr[] = ["ab", "aa", "aa", "bcd", "ab"]
// Output: 3

// Explanation: After the first iteration, we'll have: [ab, bcd, ab]. 
// We can't further destroy more strings and hence we stop and the result is 3. 

// Input: arr[] = ["tom", "jerry", "jerry", "tom"]
// Output: 0
// Explanation: After the first iteration, we'll have: [tom, tom]. 
// After the second iteration: 'empty-array' . Hence, the result is 0.



#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  // number of strings
    string arr[1000];  // assuming n ≤ 1000

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<string> st;

    for (int i = 0; i < n; i++) {
        if (!st.empty() && st.top() == arr[i]) {
            st.pop();  // destroy the pair
        } else {
            st.push(arr[i]);
        }
    }

    cout << st.size() << "\n";  // number of words remaining
    return 0;
}
