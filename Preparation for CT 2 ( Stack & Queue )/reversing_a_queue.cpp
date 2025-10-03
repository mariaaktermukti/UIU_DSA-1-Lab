// Given a queue q[], reverse the queue so that the front element becomes the rear and the rear element becomes the front,
//  while preserving the order of the remaining elements accordingly.

// Examples:

// Input: q[] = [5, 10, 15, 20, 25]
// Output: [25, 20, 15, 10, 5]
// Explanation: The original front 5 moves to the rear,
// and the rear 25 becomes the new front. All other elements follow the reversed order.

// Input: q[] = [1, 2, 3, 4, 5]
// Output: [5, 4, 3, 2, 1]
// Explanation: The queue is reversed completely: 1 goes to the rear,
// and 5 moves to the front, with all intermediate elements rearranged accordingly.

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

// Function to reverse a queue using a stack
void reverseQueue(queue<int> &q)
{
    stack<int> s;

    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }

    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
}

int main()
{
    queue<int> q;
    int n, x;

    cout << "Enter number of elements in the queue: ";
    cin >> n;

    cout << "Enter " << n << " elements of the queue:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }

    reverseQueue(q);

    cout << "Reversed queue:\n";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
