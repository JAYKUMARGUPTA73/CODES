#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Recursive solution
    int rec(int prev, int curr, int a[], int n)
    {
        if (curr == n)
        {
            return 0;
        }

        int include = 0;
        if (prev == -1 || a[curr] > a[prev])
        {
            include = 1 + rec(curr, curr + 1, a, n);
        }
        int exclude = rec(prev, curr + 1, a, n);
        return max(include, exclude);
    }

    // Memoization solution
    int mem(int prev, int curr, int a[], int n, vector<vector<int>> &dp)
    {
        if (curr == n)
        {
            return 0;
        }
        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];
        int include = 0;
        if (prev == -1 || a[curr] > a[prev])
        {
            include = 1 + mem(curr, curr + 1, a, n, dp);
        }
        int exclude = mem(prev, curr + 1, a, n, dp);
        return dp[curr][prev + 1] = max(include, exclude);
    }

    // Tabulation solution
    int tab(int a[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev])
                {
                    include = 1 + dp[curr + 1][curr + 1];
                }
                int exclude = dp[curr + 1][prev + 1];
                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0];
    }

    // Space optimization solution
    int spaceopt(int a[], int n)
    {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev])
                {
                    include = 1 + nextRow[curr + 1];
                }
                int exclude = nextRow[prev + 1];
                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0];
    }

    // Optimal n*log(n) approach
    int optimal(int a[], int n)
    {
        if (n == 0)
        {
            return 0;
        }
        vector<int> ans;
        ans.push_back(a[0]);
        for (int i = 1; i < n; i++)
        {
            if (ans.back() < a[i])
            {
                ans.push_back(a[i]);
            }
            else
            {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }

    // Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
        // Uncomment the approach you want to use:

        // Recursive
        // return rec(-1, 0, a, n);

        // Memoization
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // return mem(-1, 0, a, n, dp);

        // Tabulation
        // return tab(a, n);

        // Space optimization
        // return spaceopt(a, n);

        // Optimal n*log(n) solution
        return optimal(a, n);
    }
};

int main()
{
    // Predefined test cases
    int t = 2; // Number of test cases

    // Test case 1: Array of size 6
    int a1[] = {10, 22, 9, 33, 21, 50};
    int n1 = sizeof(a1) / sizeof(a1[0]);

    // Test case 2: Array of size 8
    int a2[] = {3, 10, 2, 1, 20, 4, 25, 6};
    int n2 = sizeof(a2) / sizeof(a2[0]);

    Solution ob;

    // Uncomment the approach you want to use in the `longestSubsequence` function and output results for predefined test cases

    // Test case 1
    cout << "Length of Longest Increasing Subsequence (Test Case 1): " << ob.longestSubsequence(n1, a1) << endl;

    // Test case 2
    cout << "Length of Longest Increasing Subsequence (Test Case 2): " << ob.longestSubsequence(n2, a2) << endl;

    return 0;
}
