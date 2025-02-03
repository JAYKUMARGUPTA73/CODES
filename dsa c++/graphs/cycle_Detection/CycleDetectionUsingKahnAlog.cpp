#include <iostream>
#include <vector>
#include <list>
#include <queue>

using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    // Create adjacency list and calculate indegree
    vector<list<int>> adjList(n);
    vector<int> indegree(n, 0);

    for (auto& edge : edges) {
        int u = edge.first - 1; // Adjust for 1-based indexing
        int v = edge.second - 1;
        adjList[u].push_back(v);
        indegree[v]++;
    }

    // Initialize queue with nodes having zero indegree
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    // Process nodes with BFS
    int cnt = 0; // Count of processed nodes

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();
        cnt++;

        for (int neighbor : adjList[frontNode]) {
            indegree[neighbor]--;
            if (indegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If cnt == n,                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              no cycle detected
    return cnt != n;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            int u, v;
            cin >> u >> v;
            edges[i] = {u, v};
        }

        bool hasCycle = detectCycleInDirectedGraph(n, edges);
        if (hasCycle) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }

    return 0;
}
