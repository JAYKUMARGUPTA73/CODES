#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        int m;
        cin>>m;
        int k;
        cin>> k;
        vector<vector<int>> mat(n,vector<int> (m,0));
        int curr=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(curr==k){
                    curr=0;
                }
                mat[j][i]=curr+1;
                curr=curr+1;
            }
        }
        for(auto i:mat){
            for(auto j:i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        t--;
    }
}