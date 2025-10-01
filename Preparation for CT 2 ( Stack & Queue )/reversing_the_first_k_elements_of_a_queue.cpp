// Given an integer k and a queue of integers, 
// The task is to reverse the order of the first k elements of the queue, 
// leaving the other elements in the same relative order.

// Only following standard operations are allowed on the queue. 

// enqueue(x): Add an item x to rear of queue
// dequeue(): Remove an item from the front of the queue
// size(): Returns the number of elements in the queue.
// front(): Finds front item.
// Example:

// Input: q = 1 2 3 4 5, k = 3
// Output: 3 2 1 4 5
// Explanation:  After reversing the first 3 elements from the given queue the resultant queue will be 3 2 1 4 5.

// Input: q = 4 3 2 1, k= 4
// Output: 1 2 3 4
// Explanation: After reversing the first 4 elements from the given queue the resultant queue will be 1 2 3 4.

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int>& q, int k) {
    if (q.empty() || k > (int)q.size() || k <= 0) return;

    stack<int> st;

    // Step 1: প্রথম k টা element stack এ push করবো
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: stack থেকে pop করে আবার queue তে push করবো (এখানে উল্টা হবে)
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: বাকি element গুলো আগের অবস্থায় রাখার জন্য আবার queue তে ঘুরিয়ে দিবো
    int t = q.size() - k;
    for (int i = 0; i < t; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, k;
    cout << "Enter number of elements in queue: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        int x; 
        cin >> x;
        q.push(x);
    }

    cout << "Enter k: ";
    cin >> k;

    reverseFirstK(q, k);

    cout << "Queue after reversing first " << k << " elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
