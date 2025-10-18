// Level order [7,4,12,3,6,8,1,5,10] → BST construct kora holo

// Inorder print korle sorted order pawa jay → BST thik ache 
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

// Insert node into BST
Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key <= root->data)
        root->left = insertBST(root->left, key);
    else
        root->right = insertBST(root->right, key);
    return root;
}

// Construct BST from level order array
Node* constructBST(int arr[], int n) {
    Node* root = nullptr;
    for (int i = 0; i < n; i++) {
        root = insertBST(root, arr[i]);
    }
    return root;
}

// Inorder traversal to print BST
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    int n;
    cout << "Enter number of nodes in level order: ";
    cin >> n;

    int arr[n];
    cout << "Enter BST nodes in level order: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    Node* root = constructBST(arr, n);

    cout << "Inorder Traversal of constructed BST: ";
    inorder(root);
    cout << endl;

    return 0;
}
