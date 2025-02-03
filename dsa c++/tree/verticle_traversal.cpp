#include <iostream>
#include <vector>
#include <queue>
#include<map>
#include<set>
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
void verticleOrderTraversal(node *root)
{
    map<int,map<int,multiset<int>>> m;
    int x = 0;
    int y = 0;
    queue<pair<node *, pair<int, int>>> q;
    q.push(make_pair(root, make_pair(x, y)));
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            pair<node *, pair<int, int>> frontnode = q.front();
            q.pop();
            m[frontnode.second.first][frontnode.second.second].insert(frontnode.first->data);
            if (frontnode.first->left)
            {
                q.push(make_pair(frontnode.first->left, make_pair(frontnode.second.first-1, frontnode.second.second+1)));
            }
            if (frontnode.first->right)
            {
                q.push(make_pair(frontnode.first->right, make_pair(frontnode.second.first+1, frontnode.second.second+1)));
            }
        }
    }
    //retrive all the values from map it will be the required verticle order
    for(auto j:m){
        for(auto i:j.second){
            for(auto k:i.second){
                cout<<k<<" ";
            }
        }
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
    root->left->left->right = new node(5);
    root->left->left->right->right = new node(6);
    root->left->right = new node(10);
    root->right->left = new node(9);
    root->right->right = new node(10);

    verticleOrderTraversal(root);
}
