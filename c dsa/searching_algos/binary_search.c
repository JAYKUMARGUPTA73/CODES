#include <stdio.h>
int binary_search(int arr[], int lb, int ub, int item)
{
    if (lb <= ub)
    {
        int mid = (ub + lb) / 2;
        if (arr[mid] == item)
        {
            return mid;
        }
        else if (arr[mid] > item)
        {
            return binary_search(arr, lb, mid - 1, item);
        }
        else
        {
            return binary_search(arr, mid + 1, ub, item);
        }
    }
    else
    {
        return -1;
    }
}

void display(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[] = {2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    int item, min, flag = 0, index;
    printf("Entered Array is:  ");
    display(arr, size);
    // check whether the given array is sorted or not:
    for (int i = 0; i < size - 1; i++)
    {
        if (arr[i + 1] < arr[i])
        {
            flag = 1;
        }
    }
    if (flag == 1)
    {
        printf("Entered array is not sorted please enter a sorted array.\n");
    }
    else
    {
        printf("\nEnter the item you wanna search for: ");
        scanf("%d", &item);
        index = binary_search(arr, 0, size - 1, item);
    }
    if (index == -1)
    {
        printf("Element %d not found in the given array\n", item);
    }
    else
    {
        printf("Element %d found at index %d.\n", item, index);
    }
}