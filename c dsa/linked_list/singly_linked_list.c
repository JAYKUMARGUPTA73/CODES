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
        printf("%d  %d\n", temp->data, temp->next);
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
struct node *insert_after(struct node *head)
{
    int item;
    struct node *temp = head;
    if (head != 0)
    {
        printf("enter the value after which you wanna insert.\n");
        scanf("%d", &item);
        while (temp != NULL && temp->data != item)
        {
            temp = temp->next;
        }
        if (temp != NULL)
        {
            // printf("%d",temp->data);
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->next = 0;
            printf("enter the value to be inserted");
            scanf("%d", &newnode->data);
            // linking after node:
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next;
            return head;
        }
        else
        {
            printf("element not found.\n");
            return head;
        }
    }
    else
    {
        printf("your linked list is empty.\n");
        return head;
    }
    return head;
}
struct node *insert_before_end(struct node *head)
{
    int item;
    struct node *temp = head, *prev = head;
    if (head != 0)
    {
        printf("enter the value before which you wanna insert.\n");
        scanf("%d", &item);
        if (item == head->data)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            newnode->next = 0;
            printf("enter the value to be inserted");
            scanf("%d", &newnode->data);
            newnode->next = head;
            head = newnode;
            return head;
        }
        else
        {
            while (temp != NULL && temp->data != item)
            {
                prev = temp;
                temp = temp->next;
            }
            if (temp != 0)
            {
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                newnode->next = 0;
                printf("enter the value to be inserted");
                scanf("%d", &newnode->data);
                // linking after node by keeping a pointer one node backward:
                newnode->next = prev->next;
                prev->next = newnode;
                prev = prev->next;
            }
            else
            {
                printf("element not found.\n");
                return head;
            }
        }
        return head;
    }
    else
    {
        printf("Your linked list is empty.\n");
        return head;
    }
}
struct node *insert_at_pos(struct node *head)
{
    int pos;
    struct node *temp = head;
    if (head != 0)
    {
        printf("Enter the position at which you wanna insert.\n");
        scanf("%d", &pos);
        if (pos == 1)
        {
            struct node *newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the value.\n");
            scanf("%d", &newnode->data);
            newnode->next = 0;
            // linking code
            newnode->next = head;
            head = newnode;
            return head;
        }
        else
        {
            for (int i = 2; i < pos; i++)
            {
                if (temp != NULL)
                {
                    temp = temp->next;
                }
                else
                {
                    break;
                }
            }
            if (temp->next != NULL)
            {
                struct node *newnode = (struct node *)malloc(sizeof(struct node));
                printf("Enter the value.\n");
                scanf("%d", &newnode->data);
                newnode->next = 0;
                newnode->next = temp->next;
                temp->next = newnode;
                return head;
            }
            else
            {
                printf("position doesnot exist.\n");
                return head; // return is necessary otherwise it will return NULL to head in main;
            }
        }
    }
    else
    {
        printf("your linked list has no elements you are inserting at pos 1.\n");
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter the value.\n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        // linking code
        head = newnode;
        return head;
    }
}
struct node *delete_node(struct node *head)
{
    struct node *temp = head, *prev;
    int item;
    printf("Enter the element you wanna delete.\n");
    scanf("%d", &item);
    if (item == head->data)
    {
        struct node *temp1 = head;
        head = head->next;
        free(temp1);
        return head;
    }
    while (temp->next != NULL)
    {
        if (temp->next->data == item)
        {
            struct node *temp1 = temp->next;
            temp->next = temp->next->next;
            free(temp1);
            return head;
        }
        temp=temp->next;
    }
    return head;
}
struct node *reversal(struct node* head){
    struct node *prev,*ptr,*next;
    prev=NULL;
    ptr=head;
    while(ptr!=NULL){
        next=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=next;
    }
    head=prev;
    return head;

}
int main()
{
    struct node *head = 0;
    int choice = 1;
    while (choice)
    {
        printf("Menu:\n1.Create.\n2.traverse.\n3.insert at end.\n4.insert at pos.\n5.insert before a node.\n6.deletion of given node.\n7.reversal of string.\n0.exit.\n");
        printf("Enter your choice.\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            head = create(head);
            break;
        case 2:
            traverse(head);
            break;
        case 3:
            head = insert_after(head);
            break;
        case 4:
            head = insert_at_pos(head);
            break;
        case 5:
            head = insert_before_end(head);
            break;
        case 6:
            head = delete_node(head);
            break;
        case 7:
            head=reversal(head);
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