#include<stdio.h>
#include<string.h>
int linear_search(int arr[],int item,int n){
    for(int i=0;i<n;i++){
        if(item==arr[i]){
            return i;
        }
    }
    return -1;
}
int main(){
    int item;
    int arr[]={0,9,8,7,6,5,4,3,2,1,2};
    int size=sizeof(arr)/sizeof(arr[0]);
    printf(("Etered array is:  "));
    for(int j=0;j<size;j++){
        printf("%d  ",arr[j]);
    }
    printf("\nenter the element you wanna search for:\n");
    scanf("%d",&item);
    int index=linear_search(arr,item,size);
    if(index==-1){
        printf("Element not found.\n");
    }else{
    printf("The element %d found at index %d.",item,index);
    }
}