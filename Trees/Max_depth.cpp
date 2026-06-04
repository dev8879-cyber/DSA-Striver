#include<iostream>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        TreeNode* node;
        val=x;
        left=nullptr;
        right=nullptr;
    }
};

int max_dep(TreeNode* root){
    if(root==nullptr) return 0;

    int lh=max_dep(root->left);
    int rh=max_dep(root->right);
    return 1+max(lh,rh);
}

int main(){

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    int m=max_dep(root);

    cout<<"Max Depth:"<<m;
    return 0;
}