#include <iostream>
using namespace std;

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int val) {
        key = val;
        left = right = nullptr;
    }
};

// Simple BST insert
Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->key)
        root->left = insertBST(root->left, key);
    else if (key > root->key)
        root->right = insertBST(root->right, key);
    return root;
}

// Construct BST from preorder array
Node* constructBST(int pre[], int n) {
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insertBST(root, pre[i]);
    }
    return root;
}

// Inorder traversal to print BST
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

int main() {
    int n;
    cout << "Enter number of elements in preorder: ";
    cin >> n;

    int pre[n];
    cout << "Enter preorder elements: ";
    for (int i = 0; i < n; i++) cin >> pre[i];

    Node* root = constructBST(pre, n);

    cout << "Inorder traversal of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
