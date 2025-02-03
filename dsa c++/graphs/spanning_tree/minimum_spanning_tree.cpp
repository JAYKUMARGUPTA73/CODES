#include <bits/stdc++.h>
using namespace std;

class MinimumSpanningTree {
public:
    vector<int> mstree(int n, vector<vector<pair<int, int>>> &adjList) {
        vector<int> key(n, INT_MAX);       // Minimum weights to pick nodes
        vector<int> parent(n, -1);         // Store MST structure
        vector<bool> visited(n, false);    // Track visited nodes

        key[0] = 0;                        // Start from node 0
        for (int count = 0; count < n - 1; count++) {
            int u = -1;

            // Pick the minimum key node not yet included in MST
            for (int i = 0; i < n; i++) {
                if (!visited[i] && (u == -1 || key[i] < key[u])) {
                    u = i;
                }
            }

            visited[u] = true;  // Include node in MST

            // Update the key values of adjacent vertices
            for (auto nbr : adjList[u]) {
                int v=nbr.first;
                int weight=nbr.second;
                if (!visited[v] && weight < key[v]) {
                    key[v] = weight;
                    parent[v] = u;
                }
            }
        }

        // Output MST edges
        for (int i = 1; i < n; i++) {
            cout << parent[i] << " - " << i << " (Weight: " << key[i] << ")\n";
        }

        return parent; // Return parent to represent the MST
    }
};

int main() {
    MinimumSpanningTree obj;
    vector<vector<int>> edges = {
        {0, 1, 2}, {1, 2, 3}, {2, 4, 7},
        {4, 1, 5}, {1, 3, 8}, {0, 3, 6}
    };

    // Prepare adjacency list
    int n = 5; // Number of nodes
    vector<vector<pair<int, int>>> adjList(n);

    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // Since the graph is undirected
    }

    obj.mstree(n, adjList);

    return 0;
}
