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

// Print BST keys in given range [n1, n2]
void printRange(Node *root, int n1, int n2)
{
    if (root == NULL)
        return;

    // Only traverse left if there might be nodes in range
    if (root->data > n1)
        printRange(root->left, n1, n2);

    // Print node if it is in range
    if (root->data >= n1 && root->data <= n2)
        cout << root->data << " ";

    // Only traverse right if there might be nodes in range
    if (root->data < n2)
        printRange(root->right, n1, n2);
}

int main()
{
    Node *root = NULL;
    int n, val, n1, n2;

    cout << "How many values to insert in BST: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Enter range n1 and n2: ";
    cin >> n1 >> n2;

    cout << "BST keys in range [" << n1 << ", " << n2 << "]: ";
    printRange(root, n1, n2);
    cout << endl;

    return 0;
}
