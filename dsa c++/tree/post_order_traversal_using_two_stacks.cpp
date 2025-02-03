#include<iostream>
#include<stack>
using namespace std;
struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data){
        val=data;
        left=nullptr;
        right=nullptr;
    }
};

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->left->right=new TreeNode(7);
    root->right->left->right->right=new TreeNode(8);

    //post order traversal
    stack<TreeNode*> st1;
    stack<TreeNode*> st2;
    TreeNode *node=root;
    st1.push(root);

    while(!st1.empty()){
        TreeNode* top=st1.top();
        st1.pop();
        st2.push(top);
        if(top->left!=nullptr){
            st1.push(top->left);
        }
        if(top->right!=nullptr){
            st1.push(top->right);
        }
    }

    while(!st2.empty()){
        TreeNode *temp=st2.top();
        st2.pop();
        cout<<temp->val<<"  ";
    }
    

}