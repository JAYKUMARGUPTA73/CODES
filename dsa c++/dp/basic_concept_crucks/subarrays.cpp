#include <iostream>
#include <vector>

using namespace std;

// Recursive function to print all subarrays starting from index `start`
void printSubarrays(vector<int>& arr, int start, int end) {
    // Base case: If start reaches the end of the array, stop recursion
    if (start == arr.size()) 
        return;

    // Print the current subarray from `start` to `end`
    cout << "[ ";
    for (int i = start; i <= end; i++)
        cout << arr[i] << " ";
    cout << "]\n";

    // Recursive call to extend the subarray
    if (end + 1 < arr.size()) {
        printSubarrays(arr, start, end + 1);
    } else {
        // Move to the next starting index and reset end
        printSubarrays(arr, start + 1, start + 1);
    }
}

// Wrapper function
void printAllSubarrays(vector<int>& arr) {
    cout << "Subarrays of: ";
    for (int num : arr) cout << num << " ";
    cout << "\n------------------------\n";

    printSubarrays(arr, 0, 0);

    cout << "------------------------\n";
}

// Driver code
int main() {
    vector<vector<int>> testCases = {
        {1, 2, 3},          // Example 1
        {4, 5},             // Example 2
        {10, 20, 30, 40},   // Example 3
        {7, 8, 9, 10, 11}   // Example 4
    };

    for (auto& testCase : testCases) {
        printAllSubarrays(testCase);
    }

    return 0;
}
