#include <bits/stdc++.h>
using namespace std;

// int rec(vector<int> &num,int x,vector<int> &dp){
//     if(x==0){
//         return 0;
//     }
//     if(x<0){
//         return INT_MAX;
//     }
//     if(dp[x]!=-1) return dp[x];
//     int mini=INT_MAX;
//     for(int i=0;i<num.size();i++){
//         int ans=rec(num,x-num[i],dp);
//         if(ans!=INT_MAX){
//             mini=min(mini,1+ans);
//         }
//     }
//     dp[x]=mini;
//     return dp[x];
// }

int minimumElements(vector<int> &num, int x) {
    // int ans= rec(num,x);
    // if(ans!=INT_MAX){
    //     return ans;
    // }else{
    //     return -1;
    // }

    // memoisation
    // vector<int> dp(x+1,-1);
    // int ans=rec(num,x,dp);
    // if(ans!=INT_MAX){
    //     return ans;
    // }else{
    //     return -1;
    // }

    // tabulisation bottom-up approach
    vector<int> dp(x + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= x; i++) {
        int mini = INT_MAX;
        for (int j = 0; j < num.size(); j++) {
            if ((i - num[j]) >= 0 && dp[i - num[j]] != INT_MAX)
                dp[i] = min(dp[i], 1 + dp[i - num[j]]);
        }
    }
    if (dp[x] == INT_MAX) {
        return -1;
    }
    return dp[x];
}

int main() {
    vector<int> num = {1, 2, 3,4};
    int x = 7;
    cout << "Minimum number of elements to sum up to " << x << " is: " << minimumElements(num, x) << endl; // Output: 3
    return 0;
}
