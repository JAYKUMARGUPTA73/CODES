#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string p="";
        cin>>p;
        string s="";
        cin>>s;
        vector<int> prefix;
        int cnt=1;
        for(int j=0;j<=s.size()-1;j++){
            if(s[j+1]==s[j]){
                cnt++;
            }else{
                prefix.push_back(cnt);
                cnt=1;
            }
        }
        int k=0;
        // for(auto l:prefix){
        //     cout<<l<<" ";
        // }
        // cout<<endl;
        int flag=0;
        int cnt1=1;
        cout<<p<<endl;
        for(int j=0;j<p.size()-1;j++){
            if(p[j+1]==p[j]){
                cnt1++;
            }else{
                // cout<<prefix[k]<<","<<cnt1<<endl;
                if(prefix[k]<cnt1||prefix[k]>2*cnt1){
                    // cout<<"No"<<endl;
                    flag=1;
                    break;
                }
                cout<<cnt1<<" ";
                cnt1=1;
                k++;
            }
        }
        if(flag==0){

            // cout<<"yes"<<endl;
        }

    }
}