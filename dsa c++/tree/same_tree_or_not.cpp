#include<iostream>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        val=data;
        left=nullptr;
        right=nullptr;
    }
};
bool checkSameTree(TreeNode* root1,TreeNode* root2){
    if(root1==nullptr || root2==nullptr){
        return (root1==root2);
    }
    return root1->val==root2->val&&checkSameTree(root1->left,root2->left)&&checkSameTree(root1->right,root2->right);
}
int main(){
    TreeNode* root1=new TreeNode(1);
    TreeNode* root2=new TreeNode(1);
    root1->left=new TreeNode(2);
    root2->left=new TreeNode(2);
    root1->right=new TreeNode(3);
    root2->right=new TreeNode(3);
    root1->left->left=new TreeNode(4);
    root2->left->left=new TreeNode(4);
    root1->left->right=new TreeNode(5);
    root2->left->right=new TreeNode(5);

    //check same or not just use any traversal and check simultaneously if values are same then continue else return false

    bool ans=checkSameTree(root1,root2);
    //0 means diff 1 means same
    cout<<ans;



}
