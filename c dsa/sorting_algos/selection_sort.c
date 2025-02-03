#include<stdio.h>
int* selection_sort(int arr[],int size){
    int min;
    for(int i=0;i<size;i++){
        min=i;
        for(int j=i+1;j<size;j++){
            if(arr[min]>arr[j]){
                min=j;
            }
        }
        //swap arr[min] and arr[i];
        int temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;   
    }
    return arr;
}
void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    printf("Enter the no. of elements you wanna sort.\n");
    int n;
    scanf("%d",&n);
    int arr[n];
    printf("enter the elements now.\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int size=sizeof(arr)/sizeof(arr[0]);
    int item;
    printf("Entered Array is:  ");
    display(arr,size);
    int* a=selection_sort(arr,size);
    printf("\nSorted array is: ");
    display(arr,size);
}