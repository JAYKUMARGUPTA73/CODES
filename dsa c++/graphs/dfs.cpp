#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>> &adjList, vector<int> &isVisited, vector<int> &ans) {
    ans.push_back(node);
    isVisited[node] = 1;

    for (auto nbr : adjList[node]) {
        if (!isVisited[nbr]) {
            dfs(nbr, adjList, isVisited, ans);
        }
    }
}

int main() {
    vector<vector<int>> edges = {{0, 2}, {2, 1}, {1, 3}, {3, 4}, {2, 4}};

    // Find the maximum node index
    int maxNode = 0;
    for (const auto &edge : edges) {
        maxNode = max({maxNode, edge[0], edge[1]});
    }

    // Prepare adjacency list
    vector<vector<int>> adjList(maxNode + 1);
    for (const auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Sort adjacency list for consistent DFS order
    for (int i = 0; i <= maxNode; i++) {
        sort(adjList[i].begin(), adjList[i].end());
    }

    vector<int> isVisited(maxNode + 1, 0);
    vector<int> ans;

    // Start DFS for all components
    for (int i = 0; i <= maxNode; i++) {
        if (!isVisited[i] && !adjList[i].empty()) {
            dfs(i, adjList, isVisited, ans);
        }
    }

    // Print DFS traversal order
    for (int num : ans) {
        cout << num << " ";
    }

    return 0;
}
