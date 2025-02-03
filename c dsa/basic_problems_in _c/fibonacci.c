#include<stdio.h>
int main(){
    int m,n,terms,sum,temp;
    printf("enter the two number.\n");
    scanf("%d%d",&m,&n);
    printf("enter no. of terms you wanna print for fibonacci.\n");
    scanf("%d",&terms);
    for(int i=0;i<terms;i++){
        sum=m+n;
        printf("%d/%d   ",m,n);
        // printf("%d  ",n);
        m=n;
        n=sum;
    }
}