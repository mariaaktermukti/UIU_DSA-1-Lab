#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Create a new node
Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Search in BST
bool search(Node* root, int value) {
    if (root == NULL) 
        return false;
    if (root->data == value) 
        return true;
    if (value < root->data) 
        return search(root->left, value);
    else 
        return search(root->right, value);
}

int main() {
    Node* root = NULL;
    int n, val;

    // Insert user input values
    cout << "How many values do you want to insert? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter value " << i+1 << ": ";
        cin >> val;
        root = insert(root, val);
    }

    // Search user input value
    cout << "Enter value to search: ";
    cin >> val;

    if (search(root, val))
        cout << val << " is found in the BST." << endl;
    else
        cout << val << " is not found in the BST." << endl;

    return 0;
}
