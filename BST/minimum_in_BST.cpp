#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create a new node
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

// Find minimum in BST
int findMin(Node *root)
{
    if (root == NULL)
    {
        cout << "BST is empty!\n";
        return -1; // or some error value
    }

    Node *current = root;
    while (current->left != NULL)
    {
        current = current->left; // go left until leftmost node
    }
    return current->data;
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

    cout << "Minimum value in BST: " << findMin(root) << endl;

    return 0;
}
