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
void allTraversal(TreeNode* root){

    stack<pair<TreeNode*,int>> st;

    vector<int> pre,in,post;

    if(root==nullptr) return;

    st.push({root,1});

    while(!st.empty()){

        auto it = st.top();
        st.pop();

        if(it.second==1){

            pre.push_back(it.first->val);

            it.second++;
            st.push(it);

            if(it.first->left){
                st.push({it.first->left,1});
            }
        }

        else if(it.second==2){

            in.push_back(it.first->val);

            it.second++;
            st.push(it);

            if(it.first->right){
                st.push({it.first->right,1});
            }
        }

        else{

            post.push_back(it.first->val);
        }
    }

    cout<<"Preorder : ";
    for(auto x:pre) cout<<x<<" ";
    cout<<"\n";

    cout<<"Inorder : ";
    for(auto x:in) cout<<x<<" ";
    cout<<"\n";

    cout<<"Postorder : ";
    for(auto x:post) cout<<x<<" ";
    cout<<"\n";
}
int main(){

    TreeNode* root = new TreeNode(1);

    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    allTraversal(root);

    return 0;
}