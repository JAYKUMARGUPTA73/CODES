#include<stdio.h>
void bubble_sort(int arr[],int size){
    int temp,flag;
    for(int i=0;i<size-1;i++){
        flag=0;
        for(int j=0;j<size-i-1;j++){
            if(arr[j+1]<arr[j]){
                flag=1;
                temp=arr[j+1];
                arr[j+1]=arr[j];
                arr[j]=temp;
            }
        }
        if(flag==0){
            break;
        }
    }
}
void display(int arr[],int n){
    printf("This is the sorted array.\n");
    for(int i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
int main(){
    int size;
    int arr[]={9,8,7,6,5,4,3,2,1,0};
    size=sizeof(arr)/sizeof(arr[0]);
    bubble_sort(arr,size);
    display(arr,size);
}