#include<stdio.h>
int main(){
    int m,n;
    printf("enter the order of mattrices.\n");
    scanf("%d%d",&m,&n);
    int a[m][n];
    printf("enter the elements of matrix.\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
    }
    int p,q;
    printf("enter the order of mattrices.\n");
    scanf("%d%d",&p,&q);
    int b[p][q];
    printf("enter the elements of matrix.\n");
    for(int i=0;i<p;i++){
        for(int j=0;j<q;j++){
            scanf("%d",&b[i][j]);
        }
    }
    int c[m][q];
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            int sum=0;
            for(int k=0;k<n;k++){
                sum=sum+a[i][k]*b[k][j];
            }
            c[i][j]=sum;
        }
    }
    printf("resultant matrix:   \n");
    for(int i=0;i<m;i++){
        for(int j=0;j<q;j++){
            printf("%3d  ",c[i][j]);
        }
        printf("\n");
    }


}