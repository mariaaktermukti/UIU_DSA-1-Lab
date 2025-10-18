#include <iostream>
#include <vector>
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

// Inorder traversal to store BST elements in a vector
void storeInorder(Node *root, vector<int> &nodes)
{
    if (root == NULL)
        return;
    storeInorder(root->left, nodes);
    nodes.push_back(root->data);
    storeInorder(root->right, nodes);
}

// Build balanced BST from sorted vector
Node *buildBalancedBST(vector<int> &nodes, int start, int end)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;
    Node *root = createNode(nodes[mid]);

    root->left = buildBalancedBST(nodes, start, mid - 1);
    root->right = buildBalancedBST(nodes, mid + 1, end);

    return root;
}

// Inorder traversal to print BST
void inorderPrint(Node *root)
{
    if (root == NULL)
        return;
    inorderPrint(root->left);
    cout << root->data << " ";
    inorderPrint(root->right);
}

int main()
{
    Node *root = NULL;
    int n, val;

    cout << "How many values to insert in BST: ";
    cin >> n;

    cout << "Enter values: ";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insert(root, val);
    }

    cout << "\nOriginal BST (inorder): ";
    inorderPrint(root);
    cout << endl;

    // Step 1: Store BST nodes in sorted array
    vector<int> nodes;
    storeInorder(root, nodes);

    // Step 2: Build balanced BST
    Node *balancedRoot = buildBalancedBST(nodes, 0, nodes.size() - 1);

    cout << "\nBalanced BST (inorder): ";
    inorderPrint(balancedRoot);
    cout << endl;

    return 0;
}
