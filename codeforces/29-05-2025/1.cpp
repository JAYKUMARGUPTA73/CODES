#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        // cout<<n<<endl;
        int maxv=INT_MIN;
        int minv=INT_MAX;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            // cout<<a<<endl;
            if(a>maxv){
                maxv=a;
            }
            if(a<minv){
                minv=a;
            }
        }
        cout<<maxv-minv<<endl;
    }
}