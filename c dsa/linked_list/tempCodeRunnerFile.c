#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void traverse(struct node *head)
{
    struct node *temp = head;
    while (temp != 0)
    {
        printf("%d  %d\n", temp->data,temp->next);
        temp = temp->next;
    }
}
struct node *create(struct node *head)
{
    int n;
    struct node *newnode, *temp;
    printf("enter the no of nodes you wanna create.\n");
    scanf("%d", &n);
    printf("Enter the data of nodes.\n");
    for (int i = 0; i < n; i++)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        scanf("%d", &newnode->data);
        // linking of nodes
        if (head == 0)
        {
            temp = head = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    struct node *head = 0;
    int choice = 1;
    while (choice)
    {
        printf("Menu:\n1.Create.\n2.traverse\n0.exit.\n");
        printf("Enter your choice.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 2:
            traverse(head);
            break;
        case 1:
            head = create(head);
            break;
        case 0:
            printf("You are exited.\n");
            exit(0);
            break;
        default:
            printf("Inavlid choice");
            break;
        }
    }
}