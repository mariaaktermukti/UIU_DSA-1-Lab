// Given a string s consisting of lowercase letters, for each position i in the
//  string (0 ≤ i < n), find the first non-repeating character in the prefix s[0..i].
//   If no such character exists, use '#'.

// Examples:

// Input: s = "aabc"
// Output: a#bb
// Explanation:
// After 'a' → first unique = 'a'
// After 'aa' → no unique → '#'
// After 'aab' → first unique = 'b'
// After 'aabc' → first unique = 'b'
// Result = a#bb

// Input: s = "bb"
// Output: b#
// Explanation:
// After 'b' → first unique = 'b'
// After 'bb'→ no unique → '#'
// Result = b#

#include <iostream>
#include <queue>
#include <string>
using namespace std;

string firstNonRepeating(string s)
{
    int freq[26] = {0}; // Frequency array for lowercase letters
    queue<char> q;
    string result = "";

    for (char c : s)
    {
        freq[c - 'a']++; // Increment frequency
        q.push(c);       // Add current char to queue

        // Remove characters from front of queue if they repeat
        while (!q.empty() && freq[q.front() - 'a'] > 1)
            q.pop();

        if (!q.empty())
            result += q.front(); // First non-repeating
        else
            result += '#'; // No unique character
    }

    return result;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;

    string ans = firstNonRepeating(s);
    cout << "Output: " << ans << endl;

    return 0;
}
