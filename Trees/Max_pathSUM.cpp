#include <iostream>
#include <algorithm>
#include <climits>

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

    int maxPathDown(TreeNode* root, int &maxi){

        if(root == nullptr){
            return 0;
        }

        int lh = max(0, maxPathDown(root->left, maxi));
        int rh = max(0, maxPathDown(root->right, maxi));

        maxi = max(maxi, lh + rh + root->val);

        return root->val + max(lh, rh);
    }

    int maxPathSum(TreeNode* root){

        int maxi = INT_MIN;

        maxPathDown(root, maxi);

        return maxi;
    }
};

int main(){

    /*
            -10
           /   \
          9     20
               /  \
              15   7
    */

    TreeNode* root = new TreeNode(-10);

    root->left = new TreeNode(9);

    root->right = new TreeNode(20);

    root->right->left = new TreeNode(15);

    root->right->right = new TreeNode(7);

    Solution obj;

    cout << "Maximum Path Sum = "
         << obj.maxPathSum(root);

    return 0;
}