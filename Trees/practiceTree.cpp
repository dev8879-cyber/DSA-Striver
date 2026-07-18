#include<iostream>
using namespace std;
#include <vector>
#include <stack>
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

vector<int> Preorder(TreeNode* root,vector<int>& vec){
    if(root==nullptr){
        return {};
    }
    vec.push_back(root->val);
    Preorder(root->left,vec);
    Preorder(root->right,vec);
    return vec;
}
int main(){

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int>vec;
    Preorder(root,vec);

    for(auto it : vec){
        cout<<it<<" ";
    }

    return 0;
}