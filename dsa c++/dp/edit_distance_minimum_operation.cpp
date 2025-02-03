#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int rec(int i, int j, string word1, string word2) {
        if (i == word1.size()) {
            return word2.size() - j;
        }
        if (j == word2.size()) {
            return word1.size() - i;
        }
        int ans = 0;
        if (word1[i] == word2[j]) {
            return rec(i + 1, j + 1, word1, word2);
        } else {
            int insertAns = 1 + rec(i, j + 1, word1, word2);
            int deleteAns = 1 + rec(i + 1, j, word1, word2);
            int replaceAns = 1 + rec(i + 1, j + 1, word1, word2);
            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return ans;
    }
    int mem(int i, int j, string word1, string word2, vector<vector<int>>& dp) {
        if (i == word1.size()) {
            return word2.size() - j;
        }
        if (j == word2.size()) {
            return word1.size() - i;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        int ans = 0;
        if (word1[i] == word2[j]) {
            return mem(i + 1, j + 1, word1, word2, dp);
        } else {
            int insertAns = 1 + mem(i, j + 1, word1, word2, dp);
            int deleteAns = 1 + mem(i + 1, j, word1, word2, dp);
            int replaceAns = 1 + mem(i + 1, j + 1, word1, word2, dp);
            ans = min(insertAns, min(deleteAns, replaceAns));
        }
        return dp[i][j] = ans;
    }

    int tab(string word1, string word2, int n, int m) {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 0; i < word1.size(); i++) {
            dp[i][word2.size()] = word1.size() - i;
        }
        for (int j = 0; j < word2.size(); j++) {
            dp[word1.size()][j] = word2.size() - j;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;
                if (word1[i] == word2[j]) {
                    ans = dp[i + 1][j + 1];
                } else {
                    int insertAns = 1 + dp[i][j + 1];
                    int deleteAns = 1 + dp[i + 1][j];
                    int replaceAns = 1 + dp[i + 1][j + 1];
                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        return tab(word1, word2, n, m);
    }
};

int main() {
    Solution sol;

    string word1, word2;

    cout << "Enter the first word: ";
    cin >> word1;

    cout << "Enter the second word: ";
    cin >> word2;

    int result = sol.minDistance(word1, word2);

    cout << "The minimum number of operations required to convert \"" 
         << word1 << "\" to \"" << word2 << "\" is: " << result << endl;

    return 0;
}
