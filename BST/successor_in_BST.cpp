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

// Find minimum in a subtree
Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Find successor of x in BST
Node *findSuccessor(Node *root, int x)
{
    Node *current = root;
    Node *successor = NULL;

    // First, find the node with value x
    while (current != NULL)
    {
        if (x < current->data)
        {
            successor = current; // potential successor
            current = current->left;
        }
        else if (x > current->data)
        {
            current = current->right;
        }
        else
        { // Node found
            if (current->right != NULL)
            {
                successor = findMin(current->right);
            }
            break;
        }
    }

    return successor; // NULL if no successor exists
}

int main()
{
    Node *root = NULL;
    int n, val, x;

    cout << "How many values to insert in BST: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Enter value to find successor: ";
    cin >> x;

    Node *succ = findSuccessor(root, x);
    if (succ == NULL)
        cout << "Successor does not exist (node is largest or not in BST).\n";
    else
        cout << "Successor of " << x << " in BST is: " << succ->data << endl;

    return 0;
}
