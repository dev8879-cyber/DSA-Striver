#include <iostream>
#include <algorithm>

using namespace std;

class TreeNode{

public:

    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x){

        val = x;
        left = nullptr;
        right = nullptr;
    }
};

class Solution{

public:

    int diameter = 0;

    int height(TreeNode* root){

        if(root == nullptr){
            return 0;
        }

        int lh = height(root->left);

        int rh = height(root->right);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }

    int diameterOfBinaryTree(TreeNode* root){

        height(root);

        return diameter;
    }
};

int main(){

    /*
              1
             / \
            2   3
           / \
          4   5
    */

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;

    cout << "Diameter of Binary Tree = "
         << obj.diameterOfBinaryTree(root);

    return 0;
}