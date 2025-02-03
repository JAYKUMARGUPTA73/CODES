#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        if (size == 0) return 0;
        if (size == 1) return cost[0];
        vector<int> dp(size);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < size; i++) {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[size - 1], dp[size - 2]);
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

    // Edge case: Empty array
    vector<int> cost5 = {};
    cout << "Minimum cost for cost5: " << solution.minCostClimbingStairs(cost5) << endl; // Output: 0

    // Edge case: Single element
    vector<int> cost6 = {5};
    cout << "Minimum cost for cost6: " << solution.minCostClimbingStairs(cost6) << endl; // Output: 5

    return 0;
}
