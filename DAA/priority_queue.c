#include<stdio.h>
#include<stdlib.h>
#define max 20
typedef struct process{
    int value;
    // int key;
}process;
process find(process PQ[],int size){
    //returns the process with highest priority.
    return PQ[1];
}
void swap(int *a,int*b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void max_heapify(process PQ[],int size,int i){
    int left=2*i;int right=(2*i)+1;
    if(left<size && right<size){
        int imax=i;
        if(PQ[imax].value<PQ[left].value){
            imax=left;
        }
        if(PQ[imax].value<PQ[right].value){
            imax=right;
        }
        if(imax!=i){
            if(imax==right){
                swap(&PQ[right].value,&PQ[i].value);
                max_heapify(PQ,size,(2*i)+1);
            }
            if(imax==left){
                swap(&PQ[left].value,&PQ[i].value);
                max_heapify(PQ,size,2*i);
            }
        }
    }
}
process extract(process PQ[],int *size){
    //we need to find the max element(located at index 1 of heap) 
    //and remove it by exchanging with the last element..
    process tempprocess=PQ[1];
    PQ[1]=PQ[*size];
    *size=*size-1;
    max_heapify(PQ,*size,1);
    return PQ[1];

}
int main(){
    process PQ[max];
    int size;
    printf("enter the heap size.\n");
    scanf("%d",&size);
    printf("enter the %d heap elements.\n",size);
    for(int i=1;i<size;i++){
        scanf("%d",&PQ[i].value);
    }
    printf("MENU.\n1.find.\n2.Extract.\n3.Insert.\n4.Increase key.\n5.Exit.\n");
    int choice;
    do{
        printf("enter your choice.\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        {
            process temp;
            temp=find(PQ,size);
            printf("%d is found with max priority.\n",temp.value);
            break;

        }
        case 2:
        {
            process temp2;
            temp2=extract(PQ,&size);
            printf("%d is found with max priority and is being removed from max_heap.\n");
            for(int i=1;i<size;i++){
                printf("%d",PQ[i].value);
            }
            break;

        }
        case 3:
            //insert();
            break;
        case 4:
            //increase_key();
            break;
        default:
            printf("invalid choice.\n");
        }

    }while (choice!=5);
    
}