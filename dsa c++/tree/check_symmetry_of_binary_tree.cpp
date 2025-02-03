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
bool isSymmetric(node *l,node *r)
{
    if(l==nullptr||r==nullptr ){
        return (l==r);
    }
    if(r->data!=l->data){
        return false;
    }
    isSymmetric(l->left,r->right);
    isSymmetric(l->right,r->left);
    return true;
}
int main()
{
    struct node *root = nullptr; // Initialize root node

    // Creating tree
    root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->left->right = new node(4);
    root->right->right = new node(3);
    root->right->left = new node(4);

    //top view function call
    bool res=isSymmetric(root->left,root->right);
    cout<<res;
}
