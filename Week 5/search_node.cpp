#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insertEnd(Node* &head, int val) {
    Node* newNode = new Node{val, NULL};   
    if (head == NULL) {  
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != NULL) { 
        temp = temp->next;
    }
    temp->next = newNode;  
}

void searchNode(Node* head, int key) {
    Node* temp = head;
    int position = 1;

    while (temp != NULL) {
        if (temp->data == key) {
            cout << "Value " << key << " found at position " << position << endl;
            return;
        }
        temp = temp->next;
        position++;
    }
    cout << "Value " << key << " not found in the list!" << endl;
}

void display(Node* head) {
    cout << "Current List: ";
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = NULL; 

    int n;
    cout << "How many nodes you want? ";
    cin >> n;

    cout << "Enter " << n << " values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        insertEnd(head, val); 
    }

    display(head);

    int key;
    cout << "Enter value to search: ";
    cin >> key;

    searchNode(head, key);

    return 0;
}
