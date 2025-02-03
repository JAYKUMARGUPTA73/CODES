// diff of l and r subtree height sould be <=1;
#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int data)
    {
        val = data;
        left = nullptr;
        right = nullptr;
    }
};
int checkforbalancetree(TreeNode *root)
{
    if (root == nullptr)
    {
        return 0;
    }
    int maxlh = max(-1, checkforbalancetree(root->left));
    int maxrh = max(-1, checkforbalancetree(root->right));
    if (abs(maxlh - maxrh) > 1)
        return -1;
    return 1 + max(maxlh, maxrh);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    // root->left=new TreeNode(2);
    // root->right=new TreeNode(3);
    // root->left->left=new TreeNode(4);
    // root->left->right=new TreeNode(5);
    // root->right->left=new TreeNode(6);
    // root->right->left->right=new TreeNode(7);
    // root->right->left->right->right=new TreeNode(8);

    int res = checkforbalancetree(root);
    if (res = -1)
    {
        cout << "its a unbalanced tree";
    }
    else
    {
        cout << "its a balanced tree";
    }
}