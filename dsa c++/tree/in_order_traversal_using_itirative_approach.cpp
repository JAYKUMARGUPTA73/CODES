#include <iostream>
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

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    stack<TreeNode *> s;
    TreeNode *node = root;
    while (node != nullptr || !s.empty())
    {
        while (node != nullptr)
        {
            s.push(node);
            node = node->left;
        }
        node = s.top();
        s.pop();
        cout << node->val << " ";
        node = node->right;
    }
    return 0;
}
