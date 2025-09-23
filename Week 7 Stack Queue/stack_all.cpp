#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Stack
{
    Node *topNode = nullptr;
    int count = 0;

    bool isEmpty()
    {
        return topNode == nullptr;
    }

    void push(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
        count++;
        cout << value << " pushed to stack\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty, cannot pop\n";
            return;
        }
        Node *temp = topNode;
        cout << topNode->data << " popped from stack\n";
        topNode = topNode->next;
        delete temp;
        count--;
    }

    int top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return -1;
        }
        return topNode->data;
    }

    int size()
    {
        return count;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack: ";
        Node *temp = topNode;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    Stack st;

    st.push(10);
    st.push(20);
    st.push(30);

    st.display();
    cout << "Top element: " << st.top() << "\n";
    cout << "Stack size: " << st.size() << "\n";

    st.pop();
    st.display();

    st.pop();
    st.pop();
    st.pop();

    if (st.isEmpty())
    {
        cout << "Stack is empty\n";
    }
    else
    {
        cout << "Stack is not empty\n";
    }

    return 0;
}
