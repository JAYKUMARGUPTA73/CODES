#include <stdio.h>
int *p_addition(int poly1[], int poly2[], int d1, int d2)
{
    int max,n;
    if (d1 > d2)
    {
        max = d1;
        n=d1-d2;
    }
    else
    {
        max = d2;
        n=d2-d1;
    }
    int temp[max];
    for (int i = 0; i <max; i++)
    {
        if (i < n)
        {
            if (d1 == max)
            {
                temp[i] = poly1[i];
            }
            else
            {
                temp[i] = poly2[i];
            }
        }
        else
        {
            temp[i]=poly1[i]+poly2[i];
        }
    }
    display(temp,max);
    return temp;
}
void input(int arr[], int size)
{
    int temp;
    printf("Enter the elements of 1st polynomial.\n");
    for (int i = 0; i <size; i++)
    {
        printf("Enter the %d element", i + 1);
        scanf("%d", &arr[i]);
    }
}
void display(int arr[], int size)
{
    printf("\nEntered polynomial is:  ");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
    }
}
int main()
{
    int d1, d2,max;
    // input of first poly
    printf("Enter the degree of 1st polynomial.\n");
    scanf("%d", &d1);
    int poly1[d1+1];
    input(poly1, d1+1);

    // input of 2nd poly
    printf("Enter the degree of 2st polynomial.\n");
    scanf("%d", &d2);
    int poly2[d2+1];
    input(poly2, d2+1);
    display(poly1, d1+1);
    display(poly2, d2+1);

    // call addition function after calculating max
    if(d1>d2){
        max=d1;
    }else{
        max=d2;
    }
    int* r=p_addition(poly1,poly2,d1+1,d2+1);
    display(r,max);
}