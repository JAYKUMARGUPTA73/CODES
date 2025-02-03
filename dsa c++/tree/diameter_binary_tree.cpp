#include<iostream>
#include<stack>
#include<limits.h>
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
int maxDiameter(TreeNode* root,int &maxd){
    if(root==nullptr){
        return 0;
    }
    int maxld=maxDiameter(root->left,maxd);
    int maxrd=maxDiameter(root->right,maxd);
    maxd=max(maxd,maxld+maxrd);
    return 1+max(maxld,maxrd);
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

    int maxd=INT_MIN;
    maxDiameter(root,maxd);
    cout<<maxd;





}