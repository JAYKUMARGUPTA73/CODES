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
int maxheight(TreeNode* root){
    if(root==nullptr){
        return 0;
    }
    int maxlh=maxheight(root->left);
    int maxrh=maxheight(root->right);
    return 1+max(maxlh,maxrh);
}

int main(){
    TreeNode *root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->right=new TreeNode(3);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(5);
    root->right->left=new TreeNode(6);
    root->right->left->right=new TreeNode(7);
    root->right->left->right->right=new TreeNode(8);

    int maxHeight=maxheight(root);
    cout<<maxHeight;




}