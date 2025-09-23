// Given a stack with push(), pop(), and empty() operations, The task is to delete the middle element of it without using any additional data structure.

// Input: s = [10, 20, 30, 40, 50]
// Output: [50, 40, 20, 10]
// Explanation: The bottom-most element will be 10 and the top-most element will be 50. Middle element will be element at index 3 from bottom, which is 30. Deleting 30, stack will look like [10, 20, 40, 50].

// Input: s = [5, 8, 6, 7, 6, 6, 5, 10, 12, 9]
// Output: [9, 12, 10, 5, 6, 7, 6, 8, 5]

#include <iostream>
#include <stack>
using namespace std;

void deleteMiddle(stack<int> &st, int current, int middle)
{
    if (st.empty() || current == middle)
    {
        st.pop();
        return;
    }

    int temp = st.top();
    st.pop();
    deleteMiddle(st, current + 1, middle);
    st.push(temp);
}

int main()
{
    stack<int> st;
    int n;

    cout << "Enter number of elements in the stack: ";
    cin >> n;

    cout << "Enter the elements (from bottom to top): ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        st.push(x);
    }

    int middle = (n + 1) / 2;

    deleteMiddle(st, 1, middle);

    cout << "Stack after deleting middle: ";
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    return 0;
}
