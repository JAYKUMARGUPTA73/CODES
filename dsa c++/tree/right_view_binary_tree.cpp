#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = right = nullptr;
    }
};
void rightView(node *root, int level, map<int, int> &m)
{
    if (root == nullptr)
    {
        return;
    }
    m[level] = root->data;
    if (root->left)
    {
        rightView(root->left, level + 1, m);
    }
    if (root->right)
    {
        rightView(root->right, level + 1, m);
    }
}
int main()
{
    struct node *root = nullptr; // Initialize root node

    // Creating tree
    root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    root->right->right = new node(7);

    map<int, int> m;
        // top view function call
        rightView(root,0,m);

        for(auto it:m){
            cout<<it.second<<" ";
        }
}
