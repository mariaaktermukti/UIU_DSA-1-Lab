// Given an array arr[], find the Previous Smaller Element (PSE) for every element in the array.

// The Previous Smaller Element of an element x is defined as the first 
// element to its left in the array that is smaller than x.
// If no such element exists for a particular position, the PSE should be considered as -1.
//  Examples: 

// Input: arr[] = [1, 6, 2]
// Output: [-1, 1, 1]
// Explanation: For the first element 1, there is no element to its left, 
// so the result is -1. For 6, the previous smaller element is 1. For 2, 
// the previous smaller element is also 1, since it is the closest smaller number when looking left.

// Input: arr[] = [1, 5, 0, 3, 4, 5]
// Output: [-1, 1, -1, 0, 3, 4]
// Explanation: 
// For 1, no element on the left → -1
// For 5, the previous smaller element is 1
// For 0, no smaller element on the left → -1
// For 3, the previous smaller element is 0
// For 4, the previous smaller element is 3
// For the last 5, the previous smaller element is 4

#include <iostream>
using namespace std;

// Stack node
struct Node {
    int val;
    Node* next;
};

// Push function
void push(Node* &top, int x) {
    Node* n = new Node();
    n->val = x;
    n->next = top;
    top = n;
}

// Pop function
void pop(Node* &top) {
    if (top == nullptr) return;
    Node* temp = top;
    top = top->next;
    delete temp;
}

// Top function
int getTop(Node* top) {
    if (top == nullptr) return -1;
    return top->val;
}

// Check if stack is empty
bool isEmpty(Node* top) {
    return top == nullptr;
}

int main() {
    int n;
    cin >> n;
    int arr[1000], pse[1000];

    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* stackTop = nullptr;

    for (int i = 0; i < n; i++) {
        // Pop elements >= current
        while (!isEmpty(stackTop) && getTop(stackTop) >= arr[i]) {
            pop(stackTop);
        }

        if (isEmpty(stackTop)) pse[i] = -1;
        else pse[i] = getTop(stackTop);

        push(stackTop, arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << pse[i] << " ";
    }
    cout << "\n";

    return 0;
}
