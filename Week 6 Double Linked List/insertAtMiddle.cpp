#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
    Node(int val) {
        data = val;
        prev = nullptr;
        next = nullptr;
    }
};

Node* head = nullptr;

void insertAtPosition(int val, int pos) {
    Node* newNode = new Node(val);

    if (pos == 1) { 
        newNode->next = head;
        if (head != nullptr) {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    Node* temp = head;
    for (int i = 1; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }

    if (temp == nullptr) {
        cout << "Invalid position!\n";
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    if (temp->next != nullptr) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void displayForward() {
    Node* temp = head;
    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    int n, val, pos;

    cout << "How many nodes initially (insert at end)? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value: ";
        cin >> val;
        insertAtPosition(val, i + 1);  
    }

    displayForward();

    cout << "Enter value to insert in middle: ";
    cin >> val;
    cout << "Enter position: ";
    cin >> pos;

    insertAtPosition(val, pos);
    displayForward();

    return 0;
}
