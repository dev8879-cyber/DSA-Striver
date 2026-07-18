#include <iostream>
using namespace std;

// Definition of Tree Node
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

    TreeNode* cur = root;

    while (true) {

        if (cur->val <= val) {

            if (cur->right != NULL)
                cur = cur->right;
            else {
                cur->right = new TreeNode(val);
                break;
            }

        } else {

            if (cur->left != NULL)
                cur = cur->left;
            else {
                cur->left = new TreeNode(val);
                break;
            }
        }
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

    cout << "Enter values:\n";

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = insertIntoBST(root, x);
    }

    cout << "\nInorder Traversal: ";
    inorder(root);

    return 0;
}