#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct Queue
{
    Node *frontNode = nullptr;
    Node *rearNode = nullptr;

    bool isEmpty()
    {
        return frontNode == nullptr;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (isEmpty())
        {
            frontNode = rearNode = newNode;
        }
        else
        {
            rearNode->next = newNode;
            rearNode = newNode;
        }
        cout << value << " enqueued\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty, cannot dequeue\n";
            return;
        }
        Node *temp = frontNode;
        cout << frontNode->data << " dequeued\n";
        frontNode = frontNode->next;
        delete temp;
        if (frontNode == nullptr)
            rearNode = nullptr;
    }

    int front()
    {
        if (isEmpty())
            return -1;
        return frontNode->data;
    }

    int rear()
    {
        if (isEmpty())
            return -1;
        return rearNode->data;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }
        Node *temp = frontNode;
        cout << "Queue: ";
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
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();
    cout << "Front: " << q.front() << "\n";
    cout << "Rear: " << q.rear() << "\n";

    q.dequeue();
    q.display();

    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}
