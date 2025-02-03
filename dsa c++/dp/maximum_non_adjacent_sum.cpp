#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rec(vector<int> &nums, int i) {
    if (i >= nums.size()) {
        return 0;
    }
    int incl = nums[i] + rec(nums, i + 2);
    int excl = rec(nums, i + 1);
    return max(incl, excl);
}

int mem(vector<int> &nums, int i, vector<int> &dp) {
    if (i >= nums.size()) {
        return 0;
    }
    if (dp[i] != -1)
        return dp[i];
    int incl = nums[i] + rec(nums, i + 2);
    int excl = rec(nums, i + 1);
    return dp[i] = max(incl, excl);
}

int tab(vector<int> &nums) {
    vector<int> dp(nums.size(), -1);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int incl = nums[i] + (i >= 2 ? dp[i - 2] : 0);
        int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }
    return dp[nums.size() - 1];
}

int spaceopt(vector<int> &nums) {
    int prev1 = nums[0];
    int prev2 = 0;

    for (int i = 1; i < nums.size(); i++) {
        int incl = prev2 + nums[i];
        int excl = prev1;
        int curr = max(incl, excl);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums) {
    // Uncomment the method you want to test
    // and comment out the others accordingly

    // Recursion
    // return rec(nums, 0);

    // Memoization
    // vector<int> dp(nums.size(), -1);
    // return mem(nums, 0, dp);

    // Tabulation
    // return tab(nums);

    // Space optimized tabulation
    return spaceopt(nums);
}

int main() {
    // Example usage:
    vector<vector<int>> test_cases = {
        {11, 55, 17, 23, 97, 11, 3, 64, 45, 25},
        {84, 83, 7, 82, 97, 67, 74, 87, 57, 16},
        {0, 85, 12, 89, 7, 91, 73, 39, 65, 52},
        // Add more test cases as needed
    };

    for (auto &nums : test_cases) {
        cout << "Maximum non-adjacent sum for array: ";
        for (auto num : nums) {
            cout << num << " ";
        }
        cout << "is: " << maximumNonAdjacentSum(nums) << endl;
    }

    return 0;
}
