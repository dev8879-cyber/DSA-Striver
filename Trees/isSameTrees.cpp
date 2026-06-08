#include <iostream>

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

    bool isSameTree(TreeNode* p, TreeNode* q){

        // both are null
        if(p == nullptr && q == nullptr){
            return true;
        }

        // one is null
        if(p == nullptr || q == nullptr){
            return false;
        }

        // values different
        if(p->val != q->val){
            return false;
        }

        // recursively check left and right
        return isSameTree(p->left, q->left) &&
               isSameTree(p->right, q->right);
    }
};

int main(){

    /*
            Tree 1              Tree 2

               1                   1
              / \                 / \
             2   3               2   3
    */

    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);

    Solution obj;

    if(obj.isSameTree(p, q)){
        cout << "Trees are same";
    }
    else{
        cout << "Trees are not same";
    }

    return 0;
}