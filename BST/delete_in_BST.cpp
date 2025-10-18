#include <iostream>
#include <queue>
#include <vector>
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

// Find minimum node (inorder successor)
Node *findMin(Node *root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete a node from BST
Node *deleteNode(Node *root, int x)
{
    if (root == NULL)
        return root;

    if (x < root->data)
        root->left = deleteNode(root->left, x);
    else if (x > root->data)
        root->right = deleteNode(root->right, x);
    else
    {
        // Node found
        if (root->left == NULL && root->right == NULL)
        {
            delete root;
            return NULL;
        }
        else if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Level-order print (normal, like array)
void printLevelOrder(Node *root)
{
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        if (node)
        {
            cout << node->data << " ";
            q.push(node->left);
            q.push(node->right);
        }
    }
    cout << endl;
}

int main()
{
    Node *root = NULL;
    int n, val, x;

    cout << "How many values to insert: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insert(root, val);
    }

    cout << "Enter value to delete: ";
    cin >> x;

    root = deleteNode(root, x);

    cout << "\nBST after deletion of " << x << endl;
    printLevelOrder(root);

    return 0;
}
