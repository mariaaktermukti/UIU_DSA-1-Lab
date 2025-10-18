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

// Find floor of x in BST
int findFloor(Node *root, int x)
{
    int floor = -1;
    Node *current = root;

    while (current != NULL)
    {
        if (current->data == x)
        {
            return x; // exact match
        }
        else if (current->data > x)
        {
            current = current->left; // go left for smaller values
        }
        else
        {
            floor = current->data;    // current node could be floor
            current = current->right; // check if there is a closer value
        }
    }

    return floor; // -1 if no floor exists
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

    cout << "Enter value to find floor: ";
    cin >> x;

    int result = findFloor(root, x);
    if (result == -1)
        cout << "Floor does not exist (all nodes are greater than " << x << ").\n";
    else
        cout << "Floor of " << x << " in BST is: " << result << endl;

    return 0;
}
