#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; 
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<vector<int>> grid(n+1,vector<int>(n+1,0));
        int size=2*n+1;
        vector<int> p(size,0);
       
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>grid[i][j];
                if(i+j<=2*n){
                    p[i+j]=grid[i][j];
                }
            }
        }
        int sum=0;
        for(int i=1;i<=2*n;i++){
            sum+=p[i];
        }
        int p1=(2*n*((2*n)+1)/2)-sum;
        cout<<p1<<" ";
        for(int i=2;i<=2*n;i++){
            cout<<p[i]<<" ";
        }
        cout<<endl;
    }
}