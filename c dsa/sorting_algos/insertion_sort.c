#include<stdio.h>
void insertion_sort(int arr[],int size){
    int j,temp;
    for(int i=1;i<size;i++){
        j=i-1;
        temp=arr[i];
        while(temp<arr[j] && j>=0){
        arr[j+1]=arr[j];
        j--;
        }
        arr[j+1]=temp;
    }
}
void display(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}
int main(){
    int arr[]={2,8,1,2,8,5,1,9,0,3,2};
    int size;
    size=sizeof(arr)/sizeof(arr[0]);
    printf("Given array:    ");
    display(arr,size);
    insertion_sort(arr,size);
    printf("\n");
    printf("The sorted array is:    ");
    display(arr,size);
}