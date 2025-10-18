#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};

// Build tree from array (heap style)
Node *buildTree(const vector<int> &arr, int i)
{
    if (i >= arr.size() || arr[i] == -1)
        return nullptr;
    Node *root = new Node(arr[i]);
    root->left = buildTree(arr, 2 * i + 1);
    root->right = buildTree(arr, 2 * i + 2);
    return root;
}

// Inorder traversal to store node values
void storeInorder(Node *root, vector<int> &values)
{
    if (!root)
        return;
    storeInorder(root->left, values);
    values.push_back(root->data);
    storeInorder(root->right, values);
}

// Inorder traversal to assign sorted values
void convertToBST(Node *root, vector<int> &values, int &index)
{
    if (!root)
        return;
    convertToBST(root->left, values, index);
    root->data = values[index++];
    convertToBST(root->right, values, index);
}

// Print inorder
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
    vector<int> arr;
    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter tree nodes in array form (-1 for NULL, space separated): ";
    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        arr.push_back(val);
    }

    Node *root = buildTree(arr, 0);

    vector<int> values;
    storeInorder(root, values);
    sort(values.begin(), values.end());

    int index = 0;
    convertToBST(root, values, index);

    cout << "Inorder of converted BST: ";
    printInorder(root);
    cout << endl;

    return 0;
}
