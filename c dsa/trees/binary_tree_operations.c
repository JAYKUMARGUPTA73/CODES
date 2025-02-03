#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
    int data;
    struct node *rt;
    struct node *lt;
};
struct node *create()
{
    char choice;
    struct node *root = (struct node *)malloc(sizeof(struct node));
    printf("Enter the node data.\n");
    scanf("%d", &root->data);
    root->lt = NULL;
    root->rt = NULL;
    printf("do node have left child.\n");
    fflush(stdin);
    scanf("%c", &choice);
    if (choice == 'y')
    {
        root->lt = create();
    }
    else
    {
        root->lt = NULL;
    }
    printf("do node have right child.\n");
    fflush(stdin);
    scanf("%c", &choice);
    if (choice == 'y')
    {
        root->rt = create();
    }
    else
    {
        root->rt = NULL;
    }
    return root;
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d  ", root->data);
        preorder(root->lt);
        preorder(root->rt);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->lt);
        printf("%d  ", root->data);
        inorder(root->rt);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {
        postorder(root->lt);
        postorder(root->rt);
        printf("%d  ", root->data);
    }
}
int count_node(struct node *root)
{
    int lst, rst;
    if (root == NULL)
    {
        return 0;
    }
    lst = count_node(root->lt);
    rst = count_node(root->rt);
    return lst + rst + 1;
}
int find_max(struct node *root)
{
    int lst, rst, max;
    if (root == NULL)
    {
        return -1;
    }
    lst = find_max(root->lt);
    rst = find_max(root->rt);
    if (lst > rst)
    {
        max = lst;
    }
    else
    {
        max = rst;
    }
    if (max > root->data)
    {
        return max;
    }
    else
    {
        return root->data;
    }
}
int find_height(struct node *root)
{
    int lst, rst, max;
    if (root == NULL)
    {
        return 0;
    }
    lst = find_height(root->lt);
    rst = find_height(root->rt);
    if (lst >= rst)
    {
        return lst + 1;
    }
    else
    {
        return rst + 1;
    }
}
struct node *search(struct node *root, int item)
{
    struct node *lst, *rst;
    if (root == 0)
    {
        return NULL;
    }
    if (root->data == item)
    {
        return root;
    }
    lst = search(root->lt, item);
    rst = search(root->rt, item);
    if (lst != NULL && rst == NULL)
    {
        return lst;
    }
    if (lst == NULL && rst != NULL)
    {
        return rst;
    }
    if (lst == NULL && rst == NULL)
    {
        return NULL;
    }
}
int main()
{
    struct node *root1 = create();
    printf("preoder:    ");
    preorder(root1);
    printf("\npostorder:    ");
    postorder(root1);
    printf("\ninorder:  ");
    inorder(root1);
    printf("\nTotal number of nodes are:  %d\n", count_node(root1));
    printf("max is %d\n", find_max(root1));
    printf("Height is %d.\n", find_height(root1));
    struct node *value = search(root1, 16);
    if (value != NULL)
    {
        printf("\nElement found is %d", value->data);
    }
    else
    {
        printf("Item not found in tree.\n");
    }
}