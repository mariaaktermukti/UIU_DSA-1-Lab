#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;    
    Node* next;    
};

void deleteAtLast(Node* &head) {
    if (head == NULL) {   
        cout << "List is empty!" << endl;
        return;
    }

    if (head->next == NULL) {
        delete head;         
        head = NULL;          
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    delete temp->next;   
    temp->next = NULL; 
}

int main() {
    Node* third = new Node{30, NULL};     
    Node* second = new Node{20, third};   
    Node* head = new Node{10, second};    

    cout << "Before Deletion at Last: ";
    for (Node* t = head; t != NULL; t = t->next)
        cout << t->data << " -> ";
    cout << "NULL\n";

    deleteAtLast(head);

    cout << "After Deletion at Last: ";
    for (Node* t = head; t != NULL; t = t->next)
        cout << t->data << " -> ";
    cout << "NULL\n";

    return 0;
}
