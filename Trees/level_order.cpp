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

vector<vector<int>> level_order(TreeNode* root, queue<TreeNode*>& q){

    vector<vector<int>> ans;

    q.push(root);

    while(!q.empty()){

        int size = q.size();
        vector<int> lev;

        for(int i=0;i<size;i++){

            TreeNode* node = q.front();
            q.pop();

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);

            lev.push_back(node->val);
        }

        ans.push_back(lev);
    }

    return ans;
}
int main(){

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    queue<TreeNode*>q;
    level_order(root,q);

    return 0;
}