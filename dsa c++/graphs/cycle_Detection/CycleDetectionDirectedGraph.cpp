#include <iostream>
#include <vector>

using namespace std;

bool dfs(int node, vector<vector<int>>& adjList, vector<bool>& visited, vector<bool>& recStack) {
    visited[node] = true;
    recStack[node] = true;

    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            //if dfs() true means cycle is found and return true at all remaining rec calls 
            if (dfs(neighbor, adjList, visited, recStack)) {
                return true;
            }
        } else if (recStack[neighbor]) {
            // Back edge found, cycle detected
            return true;
        }
    }

    recStack[node] = false; // Remove the node from the recursion stack
    return false;
}

bool detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    // Create adjacency list
    vector<vector<int>> adjList(n);

    for (auto& edge : edges) {
        int u = edge.first - 1; // Adjust for 1-based indexing
        int v = edge.second - 1;
        adjList[u].push_back(v);
    }

    // Initialize visited and recursion stack arrays
    vector<bool> visited(n, false);
    vector<bool> recStack(n, false);

    // Perform DFS for each unvisited node
    for (int i = 0; i < n; ++i) {
        if (!visited[i]) {
            if (dfs(i, adjList, visited, recStack)) {
                return true; // Cycle detected
            }
        }
    }

    return false; // No cycle detected
}

int main() {
    // Test case 1: Graph with a cycle (true)
    vector<pair<int,int>> edges1 = {{1, 2}, {2, 3}, {3, 4}, {4, 2}};
    int n1 = 4;
    bool hasCycle1 = detectCycleInDirectedGraph(n1, edges1);
    cout << "Test case 1 (with cycle): " << (hasCycle1 ? "true" : "false") << endl;

    // Test case 2: Graph without a cycle (false)
    vector<pair<int, int>> edges2 = {{1, 2}, {2, 3}, {3, 4}};
    int n2 = 4;
    bool hasCycle2 = detectCycleInDirectedGraph(n2, edges2);
    cout << "Test case 2 (without cycle): " << (hasCycle2 ? "true" : "false") << endl;

    return 0;
}
