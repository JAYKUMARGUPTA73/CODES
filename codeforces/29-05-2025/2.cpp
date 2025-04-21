#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;
bool rec(int i,int j,vector<int> &a,vector<int> &b){
    if(a.size())
}
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int j=0;j<n;j++){
            cin>>a[j];
        }
        vector<int> b(n);
        for(int j=0;j<n;j++){
            cin>>b[j];
        }
        solve(a,b);
    }
}