// We have an empty stack and can perform push and pop operations.
// We are given two arrays, a[] and b[], where a[] represents the order in which elements are
// pushed onto the stack, and b[] represents the order in which elements are popped from the stack.
//  Find whether the given push and pop sequences are valid.

// Examples:

// Input: a[] = [1, 2, 3], b[] = [2, 1, 3]
// Output: true
// Explanation:  Push 1 and 2. Since b[] requires 2 first,
// pop 2, then pop 1 next. Finally, push 3 and pop it. The push and pop sequence matches a[] and b[].

// Input: a[] = [1, 2, 3], b[] = [3, 1, 2]
// Output: false
// Explanation: After pushing 1, 2, and 3, we can pop 3 as required.
// But the next element in b[] is 1, while the stack top is 2. Since 1 is blocked under 2, this order cannot be achieved.

#include <bits/stdc++.h>
using namespace std;

bool validateStackSequences(int a[], int b[], int n)
{
    stack<int> st;
    int j = 0; // index for b[]

    for (int i = 0; i < n; i++)
    {
        st.push(a[i]);

        // pop from stack if top matches b[j]
        while (!st.empty() && st.top() == b[j])
        {
            st.pop();
            j++;
        }
    }

    // if stack is empty, sequence is valid
    return st.empty();
}

int main()
{
    int n;
    cin >> n;
    int a[1000], b[1000]; // assuming n <= 1000

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    if (validateStackSequences(a, b, n))
        cout << "true\n";
    else
        cout << "false\n";

    return 0;
}
