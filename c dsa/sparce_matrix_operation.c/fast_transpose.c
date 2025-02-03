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
void display_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int arr[4][7] = {
        {1, 2},
        {3, 4}};
    int count = 1, m = 2, n = 2;
    int b[n], c[n + 1];
    for (int i = 0; i < n; i++)
    {
        int count2 = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[j][i] != 0)
            {
                count2++;
            }
        }
        b[i] = count2;
    }
    c[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        c[i] = c[i - 1] + b[i - 1];
    }
    display_arr(b, n);
    printf("\n");
    display_arr(c, n + 1);

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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] != 0)
            {
                int temp = c[j];
                a[temp].col = i;
                a[temp].row = j;
                a[temp].value = arr[i][j];
                c[j]++;
            }
        }
    }

    printf("sparce matrix:  \n");
    display_sp(a, count);
}