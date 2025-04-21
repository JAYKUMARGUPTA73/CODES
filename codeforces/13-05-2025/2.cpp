#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        int n;
        cin>>n;
        int m;
        cin>>m;
        cout<<m<<endl;
        int l;
        cin>>l;
        int r;
        cin>>r;
        int l_=0;
        int r_=0;
        while(m!=0){
            if(l_>l){
                l_--;
                m--;
            }
            if(r_<r){
                r_++;
                m--;
            }
        }
        cout<<l_<<" "<<r_<<endl;
    }
}