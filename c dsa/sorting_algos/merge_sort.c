#include <stdio.h>
int a[20];
void merge(int arr[], int lb, int mid, int ub)
{
    printf("hello ji  ");
    int i = lb;
    int j = mid + 1;
    int k = lb;
    while (i <= mid && j <= ub)
    {
        if (arr[i] <= arr[j])
        {
            a[k] = arr[i];
            i++;
            k++;
        }
        if (arr[i] > arr[j])
        {
            a[k] = arr[j];
            j++;
            k++;
        }
    }
    if (i > mid)
    {
        while (j <= ub)
        {
            a[k] = arr[j];
            j++;
            k++;
        }
    }
    if (j > ub)
    {
        while (i <= mid)
        {
            a[k] = arr[i];
            i++;
            k++;
        }
    }
    for (k = lb; k <= ub; k++)
    {
        arr[k] = a[k];
        printf("\n%d",a[k]);
    }
}
void mergesort(int arr[], int lb, int ub)
{
    printf("hello  1 ");
    int mid = (lb + ub) / 2;
    if (lb < ub)
    {
        printf("hello  x ");
        mergesort(arr, lb, mid);

        printf("hello y   ");
        mergesort(arr, mid + 1, ub);

        printf("hello  z ");
        merge(arr, lb, mid, ub);
    }
}
void display(int arr[], int n)
{
    printf("This is the sorted array.\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}
int main()
{
    int size;
    int arr[] = {9,8,7,6,5,0};
    size = sizeof(arr) / sizeof(arr[0]);
    printf("%d", size);
    mergesort(arr, 0, size-1);
    display(arr, size);
}