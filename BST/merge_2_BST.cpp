#include <iostream>
#include <vector>
using namespace std;

// BST Node
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

// Insert a node in BST
Node *insertBST(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
        root->left = insertBST(root->left, val);
    else if (val > root->data)
        root->right = insertBST(root->right, val);
    return root;
}

// Inorder traversal to store elements in vector
void inorder(Node *root, vector<int> &arr)
{
    if (!root)
        return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

// Merge two sorted arrays
vector<int> mergeArrays(vector<int> &a, vector<int> &b)
{
    vector<int> res;
    int i = 0, j = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
            res.push_back(a[i++]);
        else
            res.push_back(b[j++]);
    }
    while (i < a.size())
        res.push_back(a[i++]);
    while (j < b.size())
        res.push_back(b[j++]);
    return res;
}

// Merge two BSTs
vector<int> mergeBSTs(Node *root1, Node *root2)
{
    vector<int> arr1, arr2;
    inorder(root1, arr1);
    inorder(root2, arr2);
    return mergeArrays(arr1, arr2);
}

int main()
{
    Node *root1 = nullptr;
    Node *root2 = nullptr;

    int n1, n2, val;

    // Input first BST
    cout << "Enter number of nodes in first BST: ";
    cin >> n1;
    cout << "Enter nodes of first BST: ";
    for (int i = 0; i < n1; i++)
    {
        cin >> val;
        root1 = insertBST(root1, val);
    }

    // Input second BST
    cout << "Enter number of nodes in second BST: ";
    cin >> n2;
    cout << "Enter nodes of second BST: ";
    for (int i = 0; i < n2; i++)
    {
        cin >> val;
        root2 = insertBST(root2, val);
    }

    vector<int> merged = mergeBSTs(root1, root2);

    cout << "Merged BST Inorder: ";
    for (int x : merged)
        cout << x << " ";
    cout << endl;

    return 0;
}
