#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool static comp(vector<int> &a, vector<int> &b) {
        if (a[0] == b[0]) {
            return a[1] >= b[1];
        }
        return a[0] < b[0];
    }

    int optimal(vector<int> &a, int n) {
        if (n == 0) {
            return 0;
        }
        vector<int> ans;
        ans.push_back(a[0]);
        for (int i = 1; i < n; i++) {
            if (ans.back() < a[i]) {
                ans.push_back(a[i]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();
                ans[index] = a[i];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        // Sort the envelopes
        sort(envelopes.begin(), envelopes.end(), comp);
        vector<int> a;
        for (auto i : envelopes) {
            a.push_back(i[1]);
        }
        return optimal(a, envelopes.size());
    }
};

int main() {
    // Test case
    Solution solution;

    vector<vector<int>> envelopes = {
        {5, 4}, {6, 4}, {6, 7}, {2, 3}
    };

    int result = solution.maxEnvelopes(envelopes);

    cout << "Maximum number of envelopes that can be Russian dolled: " << result << endl;

    return 0;
}
