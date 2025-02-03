#include <iostream>
#include <algorithm>
#include <limits.h>
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

int maxSumPath(TreeNode* root, int &maxSum) {
    if (root == nullptr) {
        return 0;
    }

    // Calculate the maximum path sum of the left and right subtrees
    int maxLeftSum = max(0, maxSumPath(root->left, maxSum));
    int maxRightSum = max(0, maxSumPath(root->right, maxSum));

    // Calculate the maximum path sum with the current node as the highest node
    maxSum = max(maxSum, maxLeftSum + maxRightSum + root->val);

    // Return the maximum path sum including the current node and one of its subtrees
    return root->val + max(maxLeftSum, maxRightSum);
}

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->left->right = new TreeNode(7);
    root->right->left->right->right = new TreeNode(8);
    root->right->left->right->right->left = new TreeNode(9);
    root->right->left->right->right->left->right = new TreeNode(10);

    int maxSumPathResult = INT_MIN;
    maxSumPath(root, maxSumPathResult);

    cout << "Maximum path sum: " << maxSumPathResult << endl;

    return 0;
}
