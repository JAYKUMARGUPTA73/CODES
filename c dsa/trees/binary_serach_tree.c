#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
struct node *binary_search(struct node *root,int item){
    struct node *lst,*rst;
    if(root==0){
        return NULL;
    }
    if(item==root->data){
        return root;
    }
    if(item>root->data){
        rst=binary_search(root->rt,item);
        return rst;
    }
    if(item<root->data){
        lst=binary_search(root->lt,item);
        return lst;
    }
    return NULL;
}
int main(){
    struct node *root1 = create();
    printf("preoder:    ");
    preorder(root1);
    printf("\npostorder:    ");
    postorder(root1);
    printf("\ninorder:  ");
    inorder(root1);
    struct node *value=binary_search(root1,16);
    if(value!=NULL){
    printf("\nElement found is %d",value->data);

    }else{
        printf("\nItem not found in tree.\n");
    }
}