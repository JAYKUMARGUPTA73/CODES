#include <stdio.h>
int partition(int arr[], int lb, int ub)
{
    int start = lb, end = ub, temp,temp1=ub;
    int pivot = arr[ub];
    while (start < end)
    {
        while (arr[start] <= pivot)
        {
            start++;
        }
        while (arr[end] > pivot)
        {
            end--;
        }
        if (start < end)
        {
            temp = arr[end];
            arr[end] = arr[start];
            arr[start] = temp;
        }
    }
    temp = arr[end];
    arr[end] = arr[temp1];
    arr[temp1] = temp;
    return end;
}
void quick_sort(int arr[], int lb, int ub)
{
    int loc;
    if (lb < ub)
    {
        loc = partition(arr, lb, ub);
        quick_sort(arr, lb, loc - 1);
        quick_sort(arr, loc + 1, ub);
    }
}
int main()
{
    int arr[] = {9, 2, 4, 5, 7, 2, 3, 0, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("given array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    quick_sort(arr, 0, n);
    printf("\nsorted array: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
}