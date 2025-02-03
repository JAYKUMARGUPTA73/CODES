#include<stdio.h>
void heapify(int i,int size,int arr[]){
    int max=arr[i];
    if(((2*i)+1)<size){
        if(max<arr[2*i]){
            max=arr[2*i];
        }
        if(max<)
    }
    
}
int main(){
    int arr[]={9,3,1,6,7,2,8,5,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=n/2;i<0;i++){
        heapify(i,n,arr)
    }
}