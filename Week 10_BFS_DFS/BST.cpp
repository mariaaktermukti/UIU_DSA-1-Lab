#include <iostream> // for input/output
using namespace std;

// ---------------- Node Structure ----------------
struct node
{
    int data;     // store node value
    node *parent; // pointer to parent node
    node *left;   // pointer to left child
    node *right;  // pointer to right child
    node(int val)
    {                  // constructor
        data = val;    // set data
        parent = NULL; // initialize parent
        left = NULL;   // initialize left child
        right = NULL;  // initialize right child
    }
};

// ---------------- BST Structure ----------------
struct binary_tree
{
    node *root;                    // pointer to root node
    binary_tree() { root = NULL; } // constructor: tree empty

    // ---------- Insert Function ----------
    void insert(node *z)
    {
        node *y = NULL; // trailing parent pointer
        node *x = root; // start from root
        while (x != NULL)
        {          // find correct position
            y = x; // update parent
            if (z->data < x->data)
                x = x->left; // go left if smaller
            else
                x = x->right; // go right if bigger
        }
        z->parent = y; // set parent of new node
        if (y == NULL)
            root = z; // tree empty → new root
        else if (z->data < y->data)
            y->left = z; // attach left child
        else
            y->right = z; // attach right child
    }

    // ---------- Search Function ----------
    node *search(int val)
    {
        node *temp = root; // start from root
        while (temp != NULL && temp->data != val)
        { // traverse tree
            if (val < temp->data)
                temp = temp->left; // go left
            else
                temp = temp->right; // go right
        }
        return temp; // return node or NULL
    }

    // ---------- Minimum Function ----------
    node *tree_min(node *x)
    {
        while (x != NULL && x->left != NULL)
            x = x->left; // go leftmost
        return x;        // return smallest node
    }

    // ---------- Inorder Traversal ----------
    void inorder(node *x)
    {
        if (x != NULL)
        {                           // if node exists
            inorder(x->left);       // visit left subtree
            cout << x->data << " "; // visit current node
            inorder(x->right);      // visit right subtree
        }
    }

    // ---------- Successor Function ----------
    node *tree_successor(node *x)
    {
        if (x->right != NULL)
            return tree_min(x->right); // right subtree min
        while (x->parent != NULL && x->parent->right == x)
            x = x->parent; // go up
        return x->parent;  // return successor
    }

    // ---------- Delete Function ----------
    void tree_delete(node *x)
    {
        // Case 1: No child
        if (x->left == NULL && x->right == NULL)
        {
            if (x->parent->left == x)
                x->parent->left = NULL; // detach left
            else
                x->parent->right = NULL; // detach right
            delete x;                    // free node
        }
        // Case 2: One child
        else if (x->left == NULL || x->right == NULL)
        {
            node *child = (x->left) ? x->left : x->right; // select child
            if (x->parent->left == x)
                x->parent->left = child; // link to parent
            else
                x->parent->right = child;
            child->parent = x->parent; // update parent
            delete x;                  // delete node
        }
        // Case 3: Two children
        else
        {
            node *succ = tree_successor(x); // find successor
            x->data = succ->data;           // copy value
            tree_delete(succ);              // delete successor
        }
    }

    // ---------- Height Function ----------
    int height(node *x)
    {
        if (x == NULL)
            return 0;                                      // empty node
        return 1 + max(height(x->left), height(x->right)); // max height
    }

    // ---------- Depth Function ----------
    int depth(node *x)
    {
        if (x == root)
            return 0;                // root depth=0
        return 1 + depth(x->parent); // go up to root
    }
};

// ---------------- Main Function ----------------
int main()
{
    binary_tree bt;  // create BST
    int choice, val; // menu choice and node value
    node *ret;       // temporary node pointer

    while (1)
    { // infinite menu loop
        cout << "\n---MENU---\n";
        cout << "1. Insert\n2. Minimum\n3. Search\n4. Inorder\n5. Successor\n6. Delete\n7. Height\n8. Depth\n9. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> val;                         // read value
            bt.insert(new node(val));           // insert node
            cout << "Inserted " << val << endl; // print confirmation
            break;

        case 2:
            ret = bt.tree_min(bt.root); // find minimum
            if (ret)
                cout << "Minimum: " << ret->data << endl;
            else
                cout << "Tree empty" << endl;
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> val;
            ret = bt.search(val); // search node
            if (ret)
                cout << "Found: " << ret->data << endl;
            else
                cout << "Not found" << endl;
            break;

        case 4:
            cout << "Inorder: ";
            bt.inorder(bt.root); // print inorder
            cout << endl;
            break;

        case 5:
            cout << "Enter value to find successor: ";
            cin >> val;
            ret = bt.search(val); // search node
            if (ret)
            {
                ret = bt.tree_successor(ret); // find successor
                if (ret)
                    cout << "Successor: " << ret->data << endl;
                else
                    cout << "No successor" << endl;
            }
            else
                cout << "Not found" << endl;
            break;

        case 6:
            cout << "Enter value to delete: ";
            cin >> val;
            ret = bt.search(val); // search node
            if (ret)
            {
                bt.tree_delete(ret); // delete node
                cout << "Deleted " << val << endl;
            }
            else
                cout << "Not found" << endl;
            break;

        case 7:
            cout << "Enter value to find height: ";
            cin >> val;
            ret = bt.search(val); // search node
            if (ret)
                cout << "Height: " << bt.height(ret) << endl;
            else
                cout << "Not found" << endl;
            break;

        case 8:
            cout << "Enter value to find depth: ";
            cin >> val;
            ret = bt.search(val); // search node
            if (ret)
                cout << "Depth: " << bt.depth(ret) << endl;
            else
                cout << "Not found" << endl;
            break;

        case 9:
            exit(0); // exit program

        default:
            cout << "Invalid choice" << endl; // wrong input
        }
    }

    return 0;
}
