#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    node(int val) {
        data = val;
        left = right = nullptr;
    }
};

int main() {
    struct node *root = nullptr; // Initialize root node

    // Creating tree
    root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);

    // Level order traversal using queue
    queue<node*> q;
    vector<vector<int>> ans;
    q.push(root);

    while (!q.empty()) {
        vector<int> level;
        int size = q.size();
        for (int i = 0; i < size; i++) {
            auto front = q.front();
            q.pop();
            level.push_back(front->data); // Push current node's data to current level
            if (front->left != nullptr) {
                q.push(front->left);
            }
            if (front->right != nullptr) {
                q.push(front->right);
            }
        }
        ans.push_back(level); // Push current level to ans
    }

    // Print level order traversal
    for (int i = 0; i < ans.size(); i++) {
        cout << "Level " << i + 1 << ": ";
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    // Clean up memory
    // Since we are exiting the program, memory deallocation is not explicitly done here
    return 0;
}
