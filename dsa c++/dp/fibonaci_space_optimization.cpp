#include<iostream>
using namespace std;
void fib(int n){
        int prev1=1;
        int prev2=0;
        cout<<prev2<<" ";
        cout<<prev1<<" ";
        int curr=0;
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
            cout<<prev1<<" ";
        }

}
int main()
{
  int a;
  cin>>a; 
          
  fib(a);
 

}