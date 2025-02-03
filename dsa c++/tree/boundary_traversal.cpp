#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <stack>
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

void addLeftBoundary(TreeNode *root, vector<int> &ans)
{
    TreeNode *curr = root->left;
    while (curr)
    {
        if (curr->left != nullptr && curr->right != nullptr)
        {
            ans.push_back(curr->val);
        }
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void addRightBoundary(TreeNode *root, vector<int> &ans)
{
    TreeNode *curr = root->right;
    vector<int> temp;
    while (curr)
    {
        if (curr->left != nullptr && curr->right != nullptr)
        {
            temp.push_back(curr->val);
        }
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }
    reverse(temp.begin(), temp.end());
    for (auto it : temp)
    {
        ans.push_back(it);
    }
}
void addLeafNodes(TreeNode *root, vector<int> &ans)
{
    if (root->left == nullptr && root->right == nullptr)
    {
        ans.push_back(root->val);
        return;
    }
    if (root->left)
        addLeafNodes(root->left, ans);
    if (root->right)
        addLeafNodes(root->right, ans);
}
int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->left->left->left = new TreeNode(8);
    root->left->left->right = new TreeNode(9);
    root->left->right->left = new TreeNode(10);
    root->left->right->right = new TreeNode(11);
    root->right->left->left = new TreeNode(12);
    root->right->left->right = new TreeNode(13);
    root->right->right->left = new TreeNode(14);
    root->right->right->right = new TreeNode(15);

    vector<int> ans;

    if(root->left!=nullptr&&root->right!=nullptr){
        ans.push_back(root->val);
    }
    addLeftBoundary(root,ans);
    addLeafNodes(root,ans);
    addRightBoundary(root,ans);

    for(auto it:ans){
        cout<<it<< "  ";
    }
}