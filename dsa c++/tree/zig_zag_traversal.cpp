#include <iostream>
#include <vector>
#include <queue>
#include<algorithm>
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
void ZTraversal(TreeNode *root, vector<vector<int>> &zig_zag)
{
    if (root == nullptr)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    int flag = 0;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            TreeNode *frontNode = q.front();
            q.pop();
            level.push_back(frontNode->val);
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        if (flag == 0)
        {
            zig_zag.push_back(level);
            flag=1;
        }else{
            reverse(level.begin(),level.end());
            zig_zag.push_back(level);
            flag=0;
        }
    }
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
    // Zig-Zag traversal
    int level=0;
    vector<vector<int>> zig_zag;
    ZTraversal(root, zig_zag);
    for(auto it:zig_zag){
        cout<<"level"<<level++<<"  :  ";
        for(auto j:it){
            cout<<j<<"  ";
        }
        cout<<endl;
    }
}