#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t){
        int n;
        cin>>n;
        vector<int> arr(n);
        int maxnum=INT_MIN;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            if(arr[i]>maxnum){
                maxnum=arr[i];
            }
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            long long tempans=0;
            for(int j=0;j<n;j++){
                tempans+=arr[i]^arr[j];
            }
            ans=max(ans,tempans);
        }
        cout<<ans<<endl;
        t--;
    }
}