// 2: Next Greater Element
// Given an array of integers, for each element find the next greater element to its right. If none
// exists, output `-1`.
// Input Format:
// First line: integer `N` (number of elements).
// Second line: `N` integers separated by spaces.
// Output Format:
// Print `N` integers, each representing the next greater element.
// Sample Input:
// 4
// 4 5 2 25
// Sample Output:
// 5 25 25 -1

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[1000];
    int nge[1000];
    int stack[1000];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (top != -1 && arr[stack[top]] <= arr[i])
        {
            top--;
        }

        if (top == -1)
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = arr[stack[top]];
        }

        top++;
        stack[top] = i;
    }

    for (int i = 0; i < n; i++)
    {
        cout << nge[i] << " ";
    }
    cout << endl;

    return 0;
}


// using linkedlist

// #include <iostream>
// using namespace std;

// struct Node {
//     int data;
//     Node* next;
// };

// int main() {
//     int n;
//     cin >> n;

//     Node* head = nullptr;
//     Node* tail = nullptr;

//     for (int i = 0; i < n; i++) {
//         int x;
//         cin >> x;
//         Node* newNode = new Node;
//         newNode->data = x;
//         newNode->next = nullptr;

//         if (!head) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             tail = newNode;
//         }
//     }

//     for (Node* i = head; i != nullptr; i = i->next) {
//         Node* j = i->next;
//         int nge = -1;
//         while (j != nullptr) {
//             if (j->data > i->data) {
//                 nge = j->data;
//                 break;
//             }
//             j = j->next;
//         }
//         cout << nge << " ";
//     }
//     cout << endl;

//     return 0;
// }
