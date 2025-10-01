// 4: Reverse a Queue Using Stack
// You are given `N` integers in a queue. Reverse the queue using a stack and print the
// elements.
// Input Format:
// First line: integer `N`.
// Second line: `N` integers (queue elements from front to rear).
// Output Format:
// Print the reversed queue elements.
// Sample Input:
// 5
// 1 2 3 4 5
// Sample Output:
// 5 4 3 2 1

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    int queue[1000];
    int stack[1000];
    int front = 0, rear = N - 1, top = -1;

    for (int i = 0; i < N; i++)
    {
        cin >> queue[i];
    }

    for (int i = 0; i < N; i++)
    {
        top++;
        stack[top] = queue[i];
    }

    while (top != -1)
    {
        cout << stack[top] << " ";
        top--;
    }
    cout << endl;

    return 0;
}
