#include <stdio.h>
struct node
{
    int row;
    int col;
    int value;
};
void display_sp(struct node a[], int count)
{
    printf("row     col   value\n");
    for (int i = 0; i < count; i++)
    {
        printf(" %d      %d      %d\n", a[i].row, a[i].col, a[i].value);
    }
}
int main()
{
    int arr[4][7] = {
        {0, 4, 0, 0, 2, 0, 0},
        {0, 3, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0},
        {7, 0, 0, 0, 0, 0, 0}
        };
    int count = 1, m = 4, n = 7;
    // to count no. of non zero terms
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                count++;
            }
        }
    }
    struct node a[count];
    a[0].row = m;
    a[0].col = n;
    a[0].value = count;
    int k = 1;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] != 0)
            {
                a[k].row = i;
                a[k].col = j;
                a[k].value = arr[i][j];
                k++;
            }
        }
    }
    printf("sparce matrix:  \n");
    display_sp(a, count);
    //transpose
    struct node b[count];
    b[0].row = n;
    b[0].col = m;
    b[0].value = count;
    for(int k=1;k<count;k++){
        b[k].row=a[k].col;
        b[k].col=a[k].row;
        b[k].value=a[k].value;
    }
    // printf("Unsorted sparce matrix:\n");
    // display_sp(b,count);
    //sorting
    int l=1;
    struct node c[count];
    c[0].row=b[0].row;
    c[0].col=b[0].col;
    c[0].value=b[0].value;
    for(int i=0;i<c[0].row;i++){
        for(int j=1;j<c[0].value;j++){
            if(i==b[j].row){
                c[l].row=b[j].row;
                c[l].col=b[j].col;
                c[l].value=b[j].value;
                l++;
            }
        }
    }
    printf("\nSorted sparce matrix:  \n");
    display_sp(c,count);
}