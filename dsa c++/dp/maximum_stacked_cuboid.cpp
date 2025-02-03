#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to check if cuboid `b` can be placed on top of cuboid `a`
    bool check(vector<int>& a, vector<int>& b) {
        if (b[0] <= a[0] && b[1] <= a[1] && b[2] <= a[2])
            return true;
        else
            return false;
    }

    // Function to solve the problem using dynamic programming (bottom-up approach)
    int solve(vector<vector<int>>& cuboids) {
        int n = cuboids.size();
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                int include = 0;
                if ((prev == -1) || check(cuboids[curr], cuboids[prev])) {
                    include = cuboids[curr][2] + nextRow[curr + 1];
                }
                int exclude = nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    // Function to find the maximum height that can be obtained by stacking cuboids
    int maxHeight(vector<vector<int>>& cuboids) {
        // Sort dimensions of each cuboid and then sort all cuboids
        for (auto& i : cuboids)
            sort(i.begin(), i.end());
        sort(cuboids.begin(), cuboids.end());
        return solve(cuboids);
    }
};

int main() {
    // Test case 1: Predefined cuboids
    vector<vector<int>> cuboids1 = {{50, 45, 20}, {95, 37, 53}, {45, 23, 12}};
    
    // Test case 2: Predefined cuboids
    vector<vector<int>> cuboids2 = {{38, 25, 45}, {76, 35, 3}, {30, 12, 37}};
    
    // Create an instance of the Solution class
    Solution sol;

    // Output for Test Case 1
    cout << "Maximum height for Test Case 1: " << sol.maxHeight(cuboids1) << endl;

    // Output for Test Case 2
    cout << "Maximum height for Test Case 2: " << sol.maxHeight(cuboids2) << endl;

    return 0;
}
