#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};

TreeNode *createNode(int val)
{
    TreeNode *newNode = new TreeNode;
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode *insertIntoBST(TreeNode *root, int val)
{
    if (root == NULL)
        return createNode(val);

    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}

// inorder traversal
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main()
{
    TreeNode *root = NULL;
    int n, val;

    cout << "How many values you want to insert: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        root = insertIntoBST(root, val);
    }

    cout << "BST in sorted order: ";
    inorder(root);
    cout << endl;

    return 0;
}
