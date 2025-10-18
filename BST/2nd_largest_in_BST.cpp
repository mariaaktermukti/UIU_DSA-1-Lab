#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create new node
Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert into BST
Node *insert(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// Find maximum node
Node *findMax(Node *root)
{
    while (root->right != NULL)
        root = root->right;
    return root;
}

// Find 2nd largest element in BST
Node *findSecondLargest(Node *root)
{
    if (!root || (!root->left && !root->right))
        return NULL; // not enough nodes

    Node *parent = NULL;
    Node *current = root;

    // Go to the largest node
    while (current->right != NULL)
    {
        parent = current;
        current = current->right;
    }

    // Case 1: largest has left subtree
    if (current->left != NULL)
    {
        return findMax(current->left);
    }

    // Case 2: largest has no left subtree
    return parent;
}

int main()
{
    Node *root = NULL;
    int n, val;

    cout << "How many values to insert: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insert(root, val);
    }

    Node *secondLargest = findSecondLargest(root);
    if (secondLargest)
        cout << "2nd largest element in BST: " << secondLargest->data << endl;
    else
        cout << "BST does not have enough nodes to find 2nd largest." << endl;

    return 0;
}
