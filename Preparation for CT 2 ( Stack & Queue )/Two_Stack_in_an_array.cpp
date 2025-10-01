// Create a data structure twoStacks that represent two stacks.
// Implementation of twoStacks should use only one array, i.e., both stacks should use the same array for storing elements.

// Following functions must be supported by twoStacks.

// push1(int x) --> pushes x to first stack
// push2(int x) --> pushes x to second stack
// pop1() --> pops an element from first stack and return the popped element
// pop2() --> pops an element from second stack and return the popped element
// Examples:

// Input: push1(2), push1(3), push2(4), pop1(), pop2(), pop2()
// Output: [3, 4, -1]
// Explanation: push1(2) the stack1 will be [2]
//                         push1(3) the stack1 will be [2,3]
//                         push2(4) the stack2 will be [4]
//                         pop1() the popped element will be 3 from stack1 and stack1 will be [2]
//                         pop2() the popped element will be 4 from stack2 and now stack2 is empty
//                         pop2() the stack2 is now empty hence returned -1

// Input: push1(1), push2(2), pop1(), push1(3), pop1(), pop1()
// Output: [1, 3, -1]
// Explanation: push1(1) the stack1 will be [1]
// push2(2) the stack2 will be [2]
// pop1() the popped element will be 1
// push1(3) the stack1 will be [3]
// pop1() the popped element will be 3
// pop1() the stack1 is now empty hence returned -1

#include <iostream>
using namespace std;

struct TwoStacks
{
    int size;
    int top1, top2;
    int *arr;

    void init(int n)
    {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }

    void push1(int x)
    {
        if (top1 < top2 - 1)
        {
            top1++;
            arr[top1] = x;
        }
        else
        {
            cout << "Stack1 Overflow\n";
        }
    }

    void push2(int x)
    {
        if (top1 < top2 - 1)
        {
            top2--;
            arr[top2] = x;
        }
        else
        {
            cout << "Stack2 Overflow\n";
        }
    }

    int pop1()
    {
        if (top1 >= 0)
        {
            int x = arr[top1];
            top1--;
            return x;
        }
        return -1;
    }

    int pop2()
    {
        if (top2 < size)
        {
            int x = arr[top2];
            top2++;
            return x;
        }
        return -1;
    }
};

int main()
{
    TwoStacks ts;
    ts.init(5);

    ts.push1(2);
    ts.push1(3);
    ts.push2(4);

    cout << ts.pop1() << " ";
    cout << ts.pop2() << " ";
    cout << ts.pop2() << " ";
}
