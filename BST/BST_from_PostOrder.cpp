#include <iostream>
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

// Function to build BST from postorder array
Node *buildBSTFromPostorder(int post[], int start, int end)
{
    if (start > end)
        return nullptr;

    int rootVal = post[end];
    Node *root = new Node(rootVal);

    // Find first element smaller than root from left
    int i;
    for (i = end - 1; i >= start; i--)
    {
        if (post[i] < rootVal)
            break;
    }

    // Left subtree: start to i
    root->left = buildBSTFromPostorder(post, start, i);
    // Right subtree: i+1 to end-1
    root->right = buildBSTFromPostorder(post, i + 1, end - 1);

    return root;
}

// Inorder traversal
void inorder(Node *root)
{
    if (!root)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main()
{
    int n;
    cout << "Enter number of elements in postorder array: ";
    cin >> n;

    int post[n];
    cout << "Enter postorder elements: ";
    for (int i = 0; i < n; i++)
        cin >> post[i];

    Node *root = buildBSTFromPostorder(post, 0, n - 1);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
