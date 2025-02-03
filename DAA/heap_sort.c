#include <stdio.h>
int swap(int *a, int *b);
int build_max_heap(int arr[], int size);
int max_heapify(int arr[], int size, int index);
void heap_sort(int arr[], int size);
int build_max_heap(int arr[], int size)
{
    for (int i = size / 2; i >= 1; i--)
    {
        max_heapify(arr, size, i);
    }
}
int max_heapify(int arr[], int size, int index)
{
    if (2 * index < size && ((2 * index) + 1) < size)
    {
        int max = arr[index];
        if (arr[2 * index] > max)
        {
            max = arr[2 * index];
        }
        if (arr[(2 * index) + 1] > max)
        {
            max = arr[(2 * index) + 1];
        }
        if (max > arr[index])
        {
            // if max is left child
            if (max == arr[2 * index])
            {
                swap(&arr[index], &arr[2 * index]);
                max_heapify(arr, size, 2 * index);
            }
            // if max is right child
            else if (max == arr[(2 * index) + 1])
            {
                swap(&arr[index], &arr[(2 * index) + 1]);
                max_heapify(arr, size, (2 * index) + 1);
            }
        }
    }
}
int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void heap_sort(int arr[], int size)
{
    // build max heap
    // swap arr[1] with last leaf
    // again heapify
    // do this n-1 times bcz last one will be automatically at right place...
    build_max_heap(arr, size);
    for (int i = size - 1; i >= 1; i--)
    {
        swap(&arr[1], &arr[i]);
        max_heapify(arr, i, 1);
    }
}
int main()
{
    printf("enter the no. of element you want to sort.\n");
    int size;
    scanf("%d", &size);
    printf("Enter %d elments you wanna sort.\n", size);
    size = size + 1;
    int arr[size];
    for (int i = 1; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    heap_sort(arr, size);
    for (int i = 1; i < size; i++)
    {
        printf("%d  ", arr[i]);
    }
    // printf("%d is the first element",arr[0]);
}