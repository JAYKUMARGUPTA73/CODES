#include <iostream>
#include <vector>
using namespace std;
long int fib(int n)
{
     vector<long int> dp(n + 1, -1);
    dp[1]=1;
    dp[0]=0;
    for(long int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
        // cout<<dp[i];
    }
    return dp[n];

}
int main()
{
    int a;
    cin >> a;

   
    long int ans = fib(a);
    cout << ans;
}