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
void topView(node *root)
{
    map<int,int> m;
    queue<pair<node *,int>> q;
    q.push(make_pair(root, 0));
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            pair<node *,int> frontnode = q.front();
            q.pop();
            m[frontnode.second]=frontnode.first->data;
            if (frontnode.first->left)
            {
                q.push(make_pair(frontnode.first->left,frontnode.second-1));
            }
            if (frontnode.first->right)
            {
                q.push(make_pair(frontnode.first->right,frontnode.second+1));
            }
        }
    }
    //retrive all the values from map it will be the required verticle order
    for(auto it:m){
        cout<<it.second<<"  ";
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
    root->left->right->left = new node(8);
    root->left->right->right= new node(9);
    root->right->left = new node(6);
    root->right->right= new node(7);



    //top view function call
    topView(root);
}
