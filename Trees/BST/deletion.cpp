#include <iostream>
using namespace std;

// Tree Node
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

// Insert into BST
TreeNode* insertIntoBST(TreeNode* root, int val) {

    if (root == NULL)
        return new TreeNode(val);

    if (val < root->val)
        root->left = insertIntoBST(root->left, val);
    else
        root->right = insertIntoBST(root->right, val);

    return root;
}

// Find minimum node in BST
TreeNode* findMin(TreeNode* root) {

    while (root->left != NULL)
        root = root->left;

    return root;
}

// Delete node from BST
TreeNode* deleteNode(TreeNode* root, int key) {

    if (root == NULL)
        return NULL;

    // Search for the node
    if (key < root->val) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->val) {
        root->right = deleteNode(root->right, key);
    }
    else {

        // Case 1: Leaf node
        if (root->left == NULL && root->right == NULL) {
            delete root;
            return NULL;
        }

        // Case 2: Only right child
        if (root->left == NULL) {
            TreeNode* temp = root->right;
            delete root;
            return temp;
        }

        // Case 2: Only left child
        if (root->right == NULL) {
            TreeNode* temp = root->left;
            delete root;
            return temp;
        }

        // Case 3: Two children
        TreeNode* successor = findMin(root->right);

        root->val = successor->val;

        root->right = deleteNode(root->right, successor->val);
    }

    return root;
}

// Inorder Traversal
void inorder(TreeNode* root) {

    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {

    TreeNode* root = NULL;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values:\n";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertIntoBST(root, x);
    }

    cout << "\nInorder before deletion: ";
    inorder(root);

    int key;
    cout << "\n\nEnter value to delete: ";
    cin >> key;

    root = deleteNode(root, key);

    cout << "\nInorder after deletion: ";
    inorder(root);

    return 0;
}