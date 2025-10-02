// Given a Queue consisting of first n natural numbers (in random order).
// The task is to check whether the given Queue elements can be arranged in
// increasing order in another Queue using a stack. The operation allowed are:

// Push and pop elements from the stack
// Pop (Or Dequeue) from the given Queue.
// Push (Or Enqueue) in the another Queue.
// Examples :

// Input : Queue[] = { 5, 1, 2, 3, 4 }
// Output : Yes
// Pop the first element of the given Queue i.e 5.
// Push 5 into the stack.
// Now, pop all the elements of the given Queue and push them to
// second Queue.
// Now, pop element 5 in the stack and push it to the second Queue.

// Input : Queue[] = { 5, 1, 2, 6, 3, 4 }
// Output : No
// Push 5 to stack.
// Pop 1, 2 from given Queue and push it to another Queue.
// Pop 6 from given Queue and push to stack.
// Pop 3, 4 from given Queue and push to second Queue.
// Now, from using any of above operation, we cannot push 5
// into the second Queue because it is below the 6 in the stack.

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    if (!(cin >> n))
        return 0;

    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        q.push(x);
    }

    stack<int> st;
    int expected = 1; // we want to produce 1,2,3,...,n in order

    // Process the input queue
    while (!q.empty())
    {
        // If front of queue matches expected, send it to output (simulate enqueue to second queue)
        if (q.front() == expected)
        {
            q.pop();
            ++expected;
        }
        // Else if stack top matches expected, pop it to output
        else if (!st.empty() && st.top() == expected)
        {
            st.pop();
            ++expected;
        }
        // Otherwise move front of queue to stack
        else
        {
            st.push(q.front());
            q.pop();
        }
    }

    // After input is exhausted, flush from stack if possible
    while (!st.empty() && st.top() == expected)
    {
        st.pop();
        ++expected;
    }

    if (expected == n + 1)
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}
