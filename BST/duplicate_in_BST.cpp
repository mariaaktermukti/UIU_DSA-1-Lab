#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    int count; // number of occurrences
};

// Create a new node
Node *createNode(int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->count = 1; // first occurrence
    return newNode;
}

// Insert into BST (duplicates increment count)
Node *insert(Node *root, int value)
{
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else
        root->count++; // duplicate found, increment count
    return root;
}

// Inorder traversal to print all values including duplicates
void printInorder(Node *root)
{
    if (root == NULL)
        return;

    printInorder(root->left);

    // Print all duplicates
    for (int i = 0; i < root->count; i++)
        cout << root->data << " ";

    printInorder(root->right);
}

// Inorder traversal to print counts of each value
void printCounts(Node *root)
{
    if (root == NULL)
        return;

    printCounts(root->left);

    cout << root->data << " appears " << root->count << " times\n";

    printCounts(root->right);
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

    cout << "\nBST with duplicates (inorder): ";
    printInorder(root);
    cout << endl;

    cout << "\nCount of each value:\n";
    printCounts(root);

    return 0;
}
