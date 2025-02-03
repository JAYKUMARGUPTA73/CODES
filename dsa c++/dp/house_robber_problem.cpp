#include <iostream>
#include <vector>
using namespace std;

// Function definitions (as provided earlier)
long long int tab(vector<int> &nums) {
    vector<long long int> dp(nums.size(), -1);
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        long long int incl = nums[i] + (i >= 2 ? dp[i - 2] : 0);
        long long int excl = dp[i - 1];
        dp[i] = max(incl, excl);
    }
    return dp[nums.size() - 1];
}

long long int houseRobber(vector<int> &valueInHouse) {
    vector<int> front, back;
    int n = valueInHouse.size();
    if (n == 1) return valueInHouse[0];
    for (int i = 0; i < n; i++) {
        if (i != n - 1) {
            front.push_back(valueInHouse[i]);
        }
        if (i != 0) {
            back.push_back(valueInHouse[i]);
        }
    }
    return max(tab(front), tab(back));
}

// Driver code
int main() {
    vector<vector<int>> testCases = {
        {2, 3, 2}, // Expected output: 3
        {1, 2, 3, 1}, // Expected output: 4
        {1, 3, 1, 3, 100}, // Expected output: 103
        {200, 3, 140, 20, 10}, // Expected output: 340
        {1}, // Expected output: 1
        {5, 5, 10, 100, 10, 5} // Expected output: 110
    };

    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test case " << i + 1 << ": " << houseRobber(testCases[i]) << endl;
    }

    return 0;
}
