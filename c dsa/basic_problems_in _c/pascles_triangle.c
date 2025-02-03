#include <stdio.h>
int factorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
    }
    return fact;
}
int perm(int n, int r)
{
    return factorial(n) / (factorial(r) * factorial(n - r));
}
int main()
{
    int m, n, size;
    printf("enter the size of row");
    scanf("%d", &size);
    m = size;
    n = (2 * m) - 1;
    int k = 1;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j <= n; j++)
        {

            if (j >= m - i + 1 && j <= m + i - 1)
            {

                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}