#include <iostream>
#include <vector>

using namespace std;

// Recursive function to generate subsets
void generateSubsets(vector<int>& arr, int i, vector<int>& current) {
    // Base case: If we have processed all elements
    if (i == arr.size()) {
        cout << "{ ";
        for (int num : current)
            cout << num << " ";
        cout << "}\n";
        return;
    }

    // Include the current element in the subset
    current.push_back(arr[i]);
    generateSubsets(arr, i + 1, current);

    // Exclude the current element and move to the next
    current.pop_back();
    generateSubsets(arr, i + 1, current);
}

// Wrapper function
void printAllSubsets(vector<int>& arr) {
    cout << "Subsets of: ";
    for (int num : arr) cout << num << " ";
    cout << "\n------------------------\n";

    vector<int> current;
    generateSubsets(arr, 0, current);

    cout << "------------------------\n";
}

// Driver code
int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3},          // Example 1
        {4, 5},             // Example 2
        {10, 20, 30, 40},   // Example 3
        {7, 8, 9, 10}       // Example 4
    };

    for (auto& testCase : testCases) {
        printAllSubsets(testCase);
    }

    return 0;
}
