#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t) {
    // Create adjacency list
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Perform BFS
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    queue<int> q;
    q.push(s);
    parent[s] = -1;
    visited[s] = true;

    while (!q.empty()) {
        int front = q.front();
        q.pop();
        for (auto i : adj[front]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = true;
                parent[i] = front;
            }
        }
    }

    // Construct the path
    vector<int> ans;
    int currentNode = t;

    // If there's no path from s to t
    if (parent.find(t) == parent.end()) {
        return {}; // return an empty vector
    }

    while (currentNode != s) {
        ans.push_back(currentNode);
        currentNode = parent[currentNode];
    }
    ans.push_back(currentNode);

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    // Define number of vertices (n) and number of edges (m)
    int n = 6;
    int m = 7;
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 5}, {4, 5}};
    int s = 0; // Source node
    int t = 5; // Target node

    // Get the shortest path
    vector<int> path = shortestPath(edges, n, m, s, t);

    // Print the path
    if (!path.empty()) {
        cout << "Shortest path from " << s << " to " << t << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path from " << s << " to " << t << " exists." << endl;
    }

    return 0;
}
