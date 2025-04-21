#include <bits/stdc++.h>
using namespace std;

bool bfs(int src, vector<vector<int>> &adjList, vector<int> &parent, vector<int> &visited) {
    queue<int> q;
    parent[src] = -1;
    visited[src] = 1;
    q.push(src);

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        for (auto nbr : adjList[frontNode]) {
            if (visited[nbr] && nbr != parent[frontNode]) {
                return true;  // Cycle detected
            } else if (!visited[nbr]) {
                q.push(nbr);
                parent[nbr] = frontNode;  // ✅ Fix: assign parent correctly
                visited[nbr] = 1;
            }
        }
    }
    return false;
}

bool isCyclic(vector<vector<int>> &adjList, int n) {
    vector<int> parent(n + 1, -1);
    vector<int> visited(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            if (bfs(i, adjList, parent, visited)) {
                return true;  // Cycle detected
            }
        }
    }
    return false;  // No cycle found
}

int main() {
    vector<vector<int>> edges = {
        {1, 2}, {2, 3}, {4, 5}, {5, 6},
        {6, 8}, {8, 9}, {5, 7}
    };
    int n = 9;

    vector<vector<int>> adjList(n + 1);
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << (isCyclic(adjList, n) ? "Cycle detected" : "No cycle") << endl;
    return 0;
}
