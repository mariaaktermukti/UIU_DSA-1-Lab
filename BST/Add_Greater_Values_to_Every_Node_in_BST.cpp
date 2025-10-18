#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Build tree from level order input
Node *buildTreeLevelOrder(int arr[], int n)
{
    if (n == 0 || arr[0] == -1)
        return nullptr;

    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < n)
    {
        Node *curr = q.front();
        q.pop();

        if (arr[i] != -1)
        {
            curr->left = new Node(arr[i]);
            q.push(curr->left);
        }
        i++;
        if (i >= n)
            break;

        if (arr[i] != -1)
        {
            curr->right = new Node(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

// Reverse inorder to add greater nodes
void addGreaterValues(Node *root, int &sum)
{
    if (!root)
        return;
    addGreaterValues(root->right, sum);
    sum += root->data;
    root->data = sum;
    addGreaterValues(root->left, sum);
}

// Inorder traversal
void printInorder(Node *root)
{
    if (!root)
        return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main()
{
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int arr[n];
    cout << "Enter tree nodes in level order (-1 for NULL): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Node *root = buildTreeLevelOrder(arr, n);

    int sum = 0;
    addGreaterValues(root, sum);

    cout << "Inorder traversal of modified BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
