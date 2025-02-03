#include<iostream>
#include<vector>
using namespace std;

// Recursive approach
int rec(int index, vector<int> &weight, vector<int> &value, int capacity) {
  if (index == 0) {
    if (weight[0] <= capacity) {
      return value[0];
    } else {
      return 0;
    }
  }

  int includeProfit = 0;
  if (weight[index] <= capacity) {
    includeProfit =
        value[index] + rec(index - 1, weight, value, capacity - weight[index]);
  }
  int excludeProfit = rec(index - 1, weight, value, capacity);
  int ans = max(includeProfit, excludeProfit);
  return ans;
}

// Memoization approach
int mem(int index, vector<int> &weight, vector<int> &value, int capacity,
        vector<vector<int>> &dp) {
  if (index == 0) {
    if (weight[0] <= capacity) {
      return value[0];
    } else {
      return 0;
    }
  }

  if (dp[index][capacity] != -1)
    return dp[index][capacity];

  int includeProfit = 0;
  if (weight[index] <= capacity) {
    includeProfit = value[index] +
                    mem(index - 1, weight, value, capacity - weight[index], dp);
  }
  int excludeProfit = mem(index - 1, weight, value, capacity, dp);
  dp[index][capacity] = max(includeProfit, excludeProfit);
  return dp[index][capacity];
}

// Tabulation approach
int tab(vector<int> &weight, vector<int> &value, int capacity) {
    int n = weight.size();
    vector<vector<int>> dp(n, vector<int>(capacity + 1, 0));

    // dp[x][y] will simply represent an subproblem with capacity y and array of weight till index x;

    // Initialize the first row (for item 0)
    for (int w = weight[0]; w <= capacity; w++) {
        dp[0][w] = value[0];
    }

    // Fill the dp table
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= capacity; w++) {
            int exclude = dp[i-1][w];
            int include = 0;
            if (weight[i] <= w) {
                include = value[i] + dp[i-1][w - weight[i]];
            }
            dp[i][w] = max(exclude, include);
        }
    }

    return dp[n-1][capacity];
}

int spaceopt(vector<int> &weight, vector<int> &value, int capacity) {
    int n = weight.size();
    vector<int> prev(capacity + 1, 0);   
    vector<int> curr(capacity + 1, 0);


    // dp[x][y] will simply represent an subproblem with capacity y and array of weight till index x;

    // Initialize the first row (for item 0)
    for (int w = weight[0]; w <= capacity; w++) {
        prev[w] = value[0];
    }

    // Fill the dp table
    for (int i = 1; i < n; i++) {
        for (int w = 0; w <= capacity; w++) {
            int exclude = prev[w];
            int include = 0;
            if (weight[i] <= w) {
                include = value[i] + prev[w - weight[i]];
            }
            curr[w] = max(exclude, include);
        }
        prev=curr;
    }

    return prev[capacity];
}


int spaceopt2(vector<int> &weight, vector<int> &value, int capacity) {
    int n = weight.size();

    vector<int> curr(capacity + 1, 0);


    // dp[x][y] will simply represent an subproblem with capacity y and array of weight till index x;

    // Initialize the first row (for item 0)
    for (int w = weight[0]; w <= capacity; w++) {
        curr[w] = value[0];
    }

    // Fill the dp table
    for (int i = 1; i < n; i++) {
        for (int w = capacity; w >= 0; w--) {
            int exclude = curr[w];
            int include = 0;
            if (weight[i] <= w) {
                include = value[i] + curr[w - weight[i]];
            }
            curr[w] = max(exclude, include);
        }
    }

    return curr[capacity];
}


int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) {
  // Uncomment the approach you want to use

  // Recursion
  // return rec(n - 1, weight, value, maxWeight);

  // Memoization
  // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
  // return mem(n - 1, weight, value, maxWeight, dp);

  // Tabulation
  // return tab(weight, value, maxWeight);

  // spaceopt(O(n*maxweight))
  // return spaceopt(weight,value,maxWeight);
  
  // spaceopt2(O(n))
  return spaceopt2(weight,value,maxWeight);
}

int main() {
    // Example 1
    vector<int> weight1 = {1, 2, 3, 4};
    vector<int> value1 = {10, 20, 30, 40};
    int maxWeight1 = 5;
    int n1 = weight1.size();
    cout << "Maximum value for Example 1: " << knapsack(weight1, value1, n1, maxWeight1) << endl;

    // Example 2
    vector<int> weight2 = {10, 20, 30};
    vector<int> value2 = {60, 100, 120};
    int maxWeight2 = 50;
    int n2 = weight2.size();
    cout << "Maximum value for Example 2: " << knapsack(weight2, value2, n2, maxWeight2) << endl;

    // Example 3
    vector<int> weight3 = {1, 3, 4, 5};
    vector<int> value3 = {1, 4, 5, 7};
    int maxWeight3 = 7;
    int n3 = weight3.size();
    cout << "Maximum value for Example 3: " << knapsack(weight3, value3, n3, maxWeight3) << endl;

    return 0;
}