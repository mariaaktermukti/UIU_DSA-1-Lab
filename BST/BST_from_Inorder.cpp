#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to build BST from inorder array
Node* buildBSTFromInorder(int arr[], int start, int end) {
    if (start > end) return nullptr;

    int mid = (start + end) / 2;
    Node* root = new Node(arr[mid]);

    root->left = buildBSTFromInorder(arr, start, mid - 1);
    root->right = buildBSTFromInorder(arr, mid + 1, end);

    return root;
}

// Inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;
    cout << "Enter number of elements in inorder array: ";
    cin >> n;

    int arr[n];
    cout << "Enter inorder elements (sorted): ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = buildBSTFromInorder(arr, 0, n - 1);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
