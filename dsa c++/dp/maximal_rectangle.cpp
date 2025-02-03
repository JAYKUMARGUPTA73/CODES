#include <iostream>
#include <vector>
#include<stack>
#include<limits.h>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        vector<int> lse(heights.size(), -1);
        vector<int> ngi(heights.size(), heights.size());

        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                lse[i] = st.top();
            }
            st.push(i);
        }

        stack<int> st2;

        for (int i = heights.size() - 1; i >= 0; i--) {
            while (!st2.empty() && heights[st2.top()] >= heights[i]) {
                st2.pop();
            }
            if (!st2.empty()) {
                ngi[i] = st2.top();
            }
            st2.push(i);
        }

        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int width = ngi[i] - lse[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }

        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        vector<vector<int>> hm(matrix.size(), vector<int>(matrix[0].size(), 0));

        for (int i = 0; i < matrix[0].size(); i++) {
            hm[0][i] = matrix[0][i] - '0';
        }

        for (int i = 1; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == '1') {
                    hm[i][j] = hm[i - 1][j] + 1;
                } else {
                    hm[i][j] = 0;
                }
            }
        }

        int ans = INT_MIN;
        for (int i = 0; i < hm.size(); i++) {
            ans = max(ans, largestRectangleArea(hm[i]));
        }
        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<char>> matrix = {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'}
    };

    int result = sol.maximalRectangle(matrix);
    cout << "The area of the largest rectangle is: " << result << endl;

    return 0;
}
