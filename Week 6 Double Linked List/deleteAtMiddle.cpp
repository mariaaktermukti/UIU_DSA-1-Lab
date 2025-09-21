#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int val)
    {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node *head = nullptr;

void insertAtEnd(int val)
{
    Node *newNode = new Node(val);
    if (head == nullptr)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != nullptr)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteAtPosition(int pos)
{
    if (head == nullptr)
    {
        cout << "List is empty! Nothing to delete.\n";
        return;
    }

    Node *temp = head;

    if (pos == 1)
    {
        head = head->next;
        if (head != nullptr)
        {
            head->prev = nullptr;
        }
        cout << "Deleted: " << temp->data << "\n";
        delete temp;
        return;
    }

    for (int i = 1; i < pos && temp != nullptr; i++)
    {
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        cout << "Invalid position!\n";
        return;
    }

    if (temp->prev != nullptr)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != nullptr)
    {
        temp->next->prev = temp->prev;
    }

    cout << "Deleted: " << temp->data << "\n";
    delete temp;
}

void displayForward()
{
    Node *temp = head;
    cout << "List: ";
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    int n, val, pos;

    cout << "How many nodes you want to insert at end? ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> val;
        insertAtEnd(val);
    }

    cout << "Initial ";
    displayForward();

    cout << "\nEnter position to delete: ";
    cin >> pos;

    deleteAtPosition(pos);
    displayForward();

    return 0;
}
