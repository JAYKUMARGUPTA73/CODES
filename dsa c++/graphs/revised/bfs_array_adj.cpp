#include <bits/stdc++.h>
using namespace std;

void bfs(int node, vector<vector<int>> &adjList, vector<int> &isVisited, vector<int> &ans) {
    queue<int> q;
    q.push(node);
    isVisited[node] = 1;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);

        for (auto nbr : adjList[frontNode]) {
            if (!isVisited[nbr]) {
                q.push(nbr);
                isVisited[nbr] = 1;
            }
        }
    }
}

int main() {
    vector<vector<int>> arr = {
        {0, 2}, {2, 1}, {1, 3}, {4, 3}, {2, 4}
    };

    // Find the maximum node index
    int maxNode = 0;
    for (const auto &edge : arr) {
        maxNode = max({maxNode, edge[0], edge[1]});
    }

    // Prepare adjacency list
    vector<vector<int>> adjList(maxNode+1);
    for (const auto &edge : arr) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    // Prepare a visited vector of correct size
    vector<int> isVisited(maxNode + 1, 0);

    // Store BFS traversal order
    vector<int> ans;
    for (int i = 0; i <= maxNode; i++) {
        if (!isVisited[i]) {
            bfs(i, adjList, isVisited, ans);
        }
    }

    // Print BFS traversal result
    for (auto node : ans) {
        cout << node << " ";
    }

    return 0;
}
