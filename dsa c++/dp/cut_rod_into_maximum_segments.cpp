#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

// Recursive method
int rec(int target, const vector<int> &nums) {
    if (target == 0) return 0;
    if (target < 0) return INT_MIN;
    int maxi = INT_MIN;
    for (int num : nums) {
        int result = rec(target - num, nums);
        if (result != INT_MIN) {
            maxi = max(maxi, result + 1);
        }
    }
    return maxi;
}

// Memoization method
int mem(int target, const vector<int> &nums, vector<int> &dp) {
    if (target == 0) return 0;
    if (target < 0) return INT_MIN;
    if (dp[target] != INT_MIN) return dp[target];
    int maxi = INT_MIN;
    for (int num : nums) {
        int result = mem(target - num, nums, dp);
        if (result != INT_MIN) {
            maxi = max(maxi, result + 1);
        }
    }
    return dp[target] = maxi;
}

// Tabulation method
int tab(int target, const vector<int> &nums) {
    vector<int> dp(target + 1, INT_MIN); // Adjust size to target + 1
    dp[0] = 0;
    for (int j = 1; j <= target; j++) {
        for (int num : nums) {
            if (j - num >= 0 && dp[j - num] != INT_MIN) {
                dp[j] = max(dp[j], dp[j - num] + 1);
            }
        }
    }
    return dp[target] == INT_MIN ? 0 : dp[target];
}

int cutSegments(int n, int x, int y, int z) {
    vector<int> nums = {x, y, z};

    // Uncomment the desired method to use

    // Recursive
    // int ans = rec(n, nums);
    // return ans < 0 ? 0 : ans;

    // Memoization
    // vector<int> dp(n + 1, INT_MIN);
    // int ans = mem(n, nums, dp);
    // return ans < 0 ? 0 : ans;

    // Tabulation
    return tab(n, nums);
}

int main() {
    int n = 7, x = 2, y = 3, z = 1;
    cout << "Maximum segments: " << cutSegments(n, x, y, z) << endl; // Expected output: 7

    int n2 = 11, x2 = 2, y2 = 3, z2 = 5;
    cout << "Maximum segments: " << cutSegments(n2, x2, y2, z2) << endl; // Expected output: 5

    return 0;
}
