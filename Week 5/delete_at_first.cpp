#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;      
    Node* next;  
};

void deleteAtFirst(Node* &head) {
    if (head == NULL) {   
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;    
    head = head->next;    
    delete temp;          
}

int main() {
    Node* third = new Node{30, NULL};

    Node* second = new Node{20, third};

    Node* head = new Node{10, second};

    cout << "Before Deletion at First: ";
    for (Node* t = head; t != NULL; t = t->next)
        cout << t->data << " -> ";
    cout << "NULL\n";

    deleteAtFirst(head);

    cout << "After Deletion at First: ";
    for (Node* t = head; t != NULL; t = t->next)
        cout << t->data << " -> ";
    cout << "NULL\n";

    return 0;
}
