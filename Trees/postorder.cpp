#include <iostream>
#include <vector>
#include <stack>

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

vector<int> Postorder(TreeNode* root, vector<int>& vec){
    if(root==nullptr){
        return {};
    }
    Postorder(root->left,vec);
    Postorder(root->right,vec);
    vec.push_back(root->val);
    return vec;
}


int main(){

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int>vec;
    Postorder(root,vec);

    for(auto it : vec){
        cout<<it<<" ";
    }

    return 0;
}