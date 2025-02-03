#include<stdio.h>
int main (){
    int arr[]={9,4,5,2,6,7,8,1};
    int size=sizeof(arr)/sizeof(arr[0]);
    
}
void merge(int *arr,int start,int mid,int end){
    int n1=mid-start+1;
    int n2=end-mid;
    int left[n1+1];
    int right[n2+1];
    
}
void mergesort(int *arr,int start,int end){
    int mid=(start+end)/2;
    if(mid!=0){
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        merge()

    }
}