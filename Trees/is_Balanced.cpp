#include<iostream>
using namespace std;
class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x){
        val=x;
        left=nullptr;
        right=nullptr;
    }
};

int dfs_Height(TreeNode* root){
    if(root==nullptr) return 0;
    int lh=dfs_Height(root->left);
    if(lh==-1) return -1;
    int rh=dfs_Height(root->right);
    if(rh==-1) return -1;
    if(abs(lh-rh)>1) return -1;
    return max(lh,rh)+1;
}

bool is_Balanced(TreeNode* root){
    return dfs_Height(root)!=-1;
}

int main(){

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    bool yay=is_Balanced(root);
    if(yay!=true){
        cout<<"Not Balanced";
    }
    else{
        cout<<"Balanced";
    }
    return 0;
}