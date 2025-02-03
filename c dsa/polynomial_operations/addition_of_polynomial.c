#include <stdio.h>
#include <stdlib.h>
struct node
{
    int coeff;
    int degree;
    struct node *next;
};
struct node *input(struct node *head)
{
    int i = 1, choice = 1;
    struct node *newnode, *temp;
    while (choice == 1)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        newnode->next = 0;
        printf("enter the degree of element %d: ", i);
        scanf("%d", &newnode->degree);
        printf("enter the coeff. of element %d: ", i);
        scanf("%d", &newnode->coeff);
        if (head == 0)
        {
            head = temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = temp->next;
        }
        i++;
        printf("enter 1 to add more elemnt and 0 to end.\n");
        scanf("%d", &choice);
    }
    return head;
}
void display(struct node *head)
{
    struct node *temp = head;
    while (temp != 0)
    {
        printf("[%d,%d,%d] ,", temp->coeff, temp->degree,temp->next);
        temp = temp->next;
    }
    printf("\n");
}
struct node *insert(struct node *head, int degree, int coeff)
{
    struct node *temp;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next = 0;
    newnode->coeff = coeff;
    newnode->degree = degree;

     // linking
        if (head == 0)
        {
            printf("heloo   ");
            head = temp = newnode;
        }
        else
        {
            printf("heloo jii   ");

            temp->next = newnode;
            temp= temp->next;
        }
        printf("[%d,%d,%d] ,", temp->coeff, temp->degree,temp->next);
        return head;
}
struct node *p_addition(struct node *head1, struct node *head2)
{
    struct node *temp1 = head1, *temp2 = head2, *head3 = 0;
    while (temp1 != 0 && temp2 != 0)
    {

        if (temp1->degree == temp2->degree)
        {
            head3=insert(head3,temp1->degree,temp1->coeff+temp2->coeff);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        if (temp1->degree > temp2->degree)
        {
            head3=insert(head3,temp1->degree,temp1->coeff);
            temp1 = temp1->next;
        }
        if(temp1->degree<temp2->degree)
        {
           head3=insert(head3,temp2->degree,temp2->coeff);
            temp2 = temp2->next;
        }

       
    }
    while (temp1 != 0)
    {
        head3=insert(head3,temp1->degree,temp1->coeff);
        temp1 = temp1->next;
    }
    while (temp2 != 0)
    {
        head3=insert(head3,temp2->degree,temp2->coeff);
        temp2 = temp2->next;
           
    }
    return head3;
}
int main()
{
    struct node *head1 = 0, *head2 = 0;
    printf("enter the first polynomial.\n");
    struct node *temp1 = input(head1);
    printf("enter the second polynomial.\n");
    struct node *temp2 = input(head2);
    display(temp1);
    display(temp2);
    struct node *temp3 = p_addition(temp1, temp2);
    display(temp3);
}