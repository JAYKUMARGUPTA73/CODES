#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(int n, vector<int>& cost, vector<int>& dp) {
        if (n == 0) {
            return cost[n];
        }
        if (n == 1) {
            return cost[1];
        }
        if (dp[n] != -1) return dp[n];
        return dp[n] = min(helper(n - 1, cost, dp), helper(n - 2, cost, dp)) + cost[n];
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        vector<int> dp(size + 1, -1);
        return min(helper(cost.size() - 1, cost, dp), helper(cost.size() - 2, cost, dp));
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> cost1 = {10, 15, 20};
    cout << "Minimum cost for cost1: " << solution.minCostClimbingStairs(cost1) << endl; // Output: 15

    // Test case 2
    vector<int> cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    cout << "Minimum cost for cost2: " << solution.minCostClimbingStairs(cost2) << endl; // Output: 6

    // Test case 3
    vector<int> cost3 = {0, 0, 0, 0};
    cout << "Minimum cost for cost3: " << solution.minCostClimbingStairs(cost3) << endl; // Output: 0

    // Additional test case
    vector<int> cost4 = {10, 15, 20, 25, 30};
    cout << "Minimum cost for cost4: " << solution.minCostClimbingStairs(cost4) << endl; // Output: 30

    return 0;
}
