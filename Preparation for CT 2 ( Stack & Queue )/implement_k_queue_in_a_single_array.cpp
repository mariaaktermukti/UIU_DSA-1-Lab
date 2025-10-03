#include <iostream>
using namespace std;

// Structure to represent k queues in a single array
struct KQueue
{
    int *arr;   // Array to store queue elements
    int *front; // Front indices of queues
    int *rear;  // Rear indices of queues
    int *next;  // Next free or next element
    int n;      // Size of array
    int k;      // Number of queues
    int free;   // Beginning index of free list
};

// Initialize the KQueue
void initKQueue(KQueue &q, int k1, int n1)
{
    q.k = k1;
    q.n = n1;
    q.arr = new int[n1];
    q.front = new int[k1];
    q.rear = new int[k1];
    q.next = new int[n1];

    // Initialize all queues as empty
    for (int i = 0; i < k1; i++)
    {
        q.front[i] = -1;
        q.rear[i] = -1;
    }

    // Initialize free list
    for (int i = 0; i < n1 - 1; i++)
        q.next[i] = i + 1;
    q.next[n1 - 1] = -1;

    q.free = 0;
}

// Check if a queue is empty
bool isEmpty(KQueue &q, int qn)
{
    return q.front[qn] == -1;
}

// Enqueue element x into queue qn
void enqueue(KQueue &q, int qn, int x)
{
    if (q.free == -1)
    {
        cout << "Queue Overflow\n";
        return;
    }

    int i = q.free;     // Get first free index
    q.free = q.next[i]; // Update free to next free slot

    if (q.front[qn] == -1) // If queue is empty
        q.front[qn] = i;
    else
        q.next[q.rear[qn]] = i; // Link new element after rear

    q.next[i] = -1; // Mark next of new element as end
    q.rear[qn] = i; // Update rear
    q.arr[i] = x;   // Store element
}

// Dequeue element from queue qn
int dequeue(KQueue &q, int qn)
{
    if (isEmpty(q, qn))
        return -1;

    int i = q.front[qn];     // Get front index
    q.front[qn] = q.next[i]; // Move front to next element

    if (q.front[qn] == -1) // If queue becomes empty
        q.rear[qn] = -1;

    q.next[i] = q.free; // Add this index to free list
    q.free = i;

    return q.arr[i];
}

// Driver code
int main()
{
    int n = 10, k = 3;
    KQueue q;
    initKQueue(q, k, n);

    enqueue(q, 0, 10);
    enqueue(q, 1, 20);
    enqueue(q, 2, 30);
    enqueue(q, 1, 40);

    cout << dequeue(q, 0) << endl; // 10
    cout << dequeue(q, 1) << endl; // 20
    cout << dequeue(q, 1) << endl; // 40
    cout << dequeue(q, 2) << endl; // 30
    cout << dequeue(q, 2) << endl; // -1

    return 0;
}
