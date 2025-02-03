#include <stdio.h>
#include <stdlib.h>


struct node
{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(
        sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}
struct node *insert(struct node *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    return node;
}

// Function to do inorder traversal of BST
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

// Driver Code
int main()
{
    int num,n;
    struct node *root = NULL;

    
    root = insert(root, 50);
    printf("enter the number of items you wanna insert..\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("enter the element.\n");
        scanf("%d",&num);
        insert(root,num);
    }

    // insert(root, 30);

    // insert(root, 20);

    // insert(root, 40);

    // insert(root, 70);

    // insert(root, 60);

    // insert(root, 80);

    // inorder(root);

    return 0;
}
