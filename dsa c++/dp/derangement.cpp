#include<iostream>
using namespace std;
#include <vector>
#define MOD 1000000007

long long int rec(int n) {
    if (n == 0 || n == 1) {
        return 0;
    }
    if (n == 2) {
        return 1;
    }
    return ((n - 1) * (rec(n - 1) + rec(n - 2))) % MOD;
}

long long int mem(int n, std::vector<long long int>& dp) {
    if (dp[n] != -1) return dp[n];
    
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;

    if (n > 2) {
        dp[n] = ((n - 1) * (mem(n - 1, dp) + mem(n - 2, dp)) % MOD) % MOD;
    }

    return dp[n];
}

long long int tab(int n) {
    std::vector<long long int> dp(n + 1, -1);

    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2]) % MOD) % MOD;
    }
    return dp[n];
}

long long int countDerangements(int n) {
    // recursion
    // long long int ans=rec(n);
    // return (ans%MOD);

    // memoisation
    // std::vector<long long int> dp(n + 1, -1);
    // mem(n, dp);
    // return dp[n];

    // tabulation
    return tab(n);
}
int main() {
    int n;
    cout << "Enter a value for n: ";
    cin >> n;

    long long int result = countDerangements(n);
    cout << "The number of derangements for " << n << " is: " << result << std::endl;

    return 0;
}