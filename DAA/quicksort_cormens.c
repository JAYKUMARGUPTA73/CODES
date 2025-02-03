/*cormens quicksort: 
1).pivot element is the last element.
2).there is a i-list where we will append the elements less than pivot;
*/
#include <stdio.h>
void quicksort(int *arr, int start, int end);
void display(int *arr, int size)
{
    printf("sorted array: ");
    for (int i = 0; i < size - 1; i++)
    {
        printf(" %d ,", arr[i]);
    }
    printf(" %d.", arr[size - 1]);
}
int main()
{
    int arr[] = {9, 9, 2, 5, 30, 7, 6, 8};
    int size = sizeof(arr) / sizeof(arr[0]);
    quicksort(arr, 0, size - 1);
    display(arr, size);
}
int partition(int *arr, int start, int end)
{
    int pivot = end;
    int i = start - 1;
    for (int j = start; j < end; j++)
    {
        if (arr[j] <= arr[pivot])
        {
            // swap arr[j] and arr[++i];
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    // swap arr[++i] with arr[pivot]
    int temp = arr[pivot];
    arr[pivot] = arr[i + 1];
    arr[i + 1] = temp;
    return i + 1;
}
void quicksort(int arr[], int start, int end)
{
    int loc;
    // printf("%d  %d  \n",start,end);
    if (start < end)
    {
        loc = partition(arr, start, end);
        quicksort(arr, start, loc - 1);
        quicksort(arr, loc + 1, end);
    }
    return;
}