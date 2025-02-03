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

bool pathToNode(int node, TreeNode *root, vector<int> &ans) {
    if (root == nullptr) {
        return false;
    }
    
    ans.push_back(root->val);
    
    if (root->val == node) {
        return true;
    }
    
    if (pathToNode(node, root->left, ans) || pathToNode(node, root->right, ans)) {
        return true;
    }
    
    // If the node is not found in either subtree, backtrack
    ans.pop_back();
    return false;
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);
    root->right = new TreeNode(3);

    int node = 6;
    vector<int> ans;
    
    if (pathToNode(node, root, ans)) {
        for (auto it : ans) {
            cout << it << " ";
        }
    } else {
        cout << "Node not found";
    }
    
    return 0;
}
