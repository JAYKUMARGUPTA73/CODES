#include<iostream>
#include<vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data) {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};

TreeNode* lowestCommonAncestor(TreeNode *node1, TreeNode *node2, TreeNode *root) {
    if(root==NULL||root==node1||root==node2){
        return root;
    }
    TreeNode *leftLCA = lowestCommonAncestor(node1, node2, root->left);
    TreeNode *rightLCA = lowestCommonAncestor(node1, node2, root->right);
    
    if(leftLCA==NULL){
        return rightLCA;
    }else if(rightLCA==NULL){
        return leftLCA;
    }else{
        //both left and right are not null
        return root;
    }
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(3);

    TreeNode *node1 = root->left->right->left;
    TreeNode *node2 = root->left->left;
    
    TreeNode *lca = lowestCommonAncestor(node1, node2, root);
    if (lca != nullptr) {
        cout << "Lowest Common Ancestor of " << node1->val << " and " << node2->val << " is: " << lca->val << endl;
    } else {
        cout << "Lowest Common Ancestor not found" << endl;
    }
    
    return 0;
}
