#include <iostream>
#include <vector>
#include <stack>
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

        for(int i = 0; i < heights.size(); i++) {
            cout << "LSE[" << i << "] = " << lse[i] << endl;
        }
        
        int maxArea = 0;
        for (int i = 0; i < heights.size(); i++) {
            int width = ngi[i] - lse[i] - 1;
            int area = heights[i] * width;
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};

int main() {
    Solution sol;
    
    vector<int> heights = {2, 1, 5, 6, 2, 3};

    cout << "Input heights: ";
    for (int h : heights) {
        cout << h << " ";
    }
    cout << endl;

    int result = sol.largestRectangleArea(heights);

    cout << "Largest rectangle area: " << result << endl;

    return 0;
}
