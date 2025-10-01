// 3: Queue Using Two Stacks
// You are given queries to perform enqueue and dequeue operations on a queue implemented
// using two stacks.
// Input Format:
// First line: integer `Q` (number of queries).
// Next `Q` lines contain one of the following:
//  - `1 X` Enqueue element `X`.
//  - `2` Dequeue element from front.
//  - `3` Print the front element.
// Output Format:
// For each query type `3`, print the front element.
// Sample Input:
// 6
// 1 10
// 1 20
// 3
// 2
// 3
// 2
// Sample Output:
// 10
// 20


#include <iostream>
using namespace std;

int main()
{
    int Q;
    cin >> Q;

    int stack1[1000], stack2[1000]; 
    int top1 = -1, top2 = -1;

    while (Q--)
    {
        int type;
        cin >> type;

        if (type == 1)
        {
            int x;
            cin >> x;
            top1++;
            stack1[top1] = x;
        }
        else if (type == 2)
        {
            if (top2 == -1)
            {
                while (top1 != -1)
                {
                    top2++;
                    stack2[top2] = stack1[top1];
                    top1--;
                }
            }
            if (top2 != -1)
                top2--; 
        }
        else if (type == 3)
        {
            if (top2 == -1)
            {
                while (top1 != -1)
                {
                    top2++;
                    stack2[top2] = stack1[top1];
                    top1--;
                }
            }
            if (top2 != -1)
                cout << stack2[top2] << endl;
        }
    }

    return 0;
}
