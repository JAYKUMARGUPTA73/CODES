#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
void inorder(struct node *root){
    while (root!=NULL)       
    {
        inorder(root->left);
        printf("%d  ",root->data);
        inorder(root->right);

    }
    
}
// void create(struct node *root){
//     char choice;
//     printf("enter the root data:\n");
//     scanf("%d",&root->data);
//     printf("does root have left child.\n");
//     scanf("%c",&choice);
//     if(choice=='y'){
//         root=root->left;
//     }
//     printf("does root have right child");
//     scanf("%c",&choice);
//     if(choice=='y'){
//         root=root->right;
//     }
// }
struct node *newnode(int value){
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    temp->data=value;
    temp->left=temp->right=NULL;
    return temp;
}
struct node *insert(struct node *root,int value){
    if(root==NULL){
        return newnode(value);
    }
    if(value>root->data){
        root->right=insert(root->right,value);
    }else{
        root->left=insert(root->left,value);
    }
}
int main(){
    struct node *root1;
    create(root1);
    
}