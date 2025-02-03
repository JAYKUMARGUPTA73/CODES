#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>> &adjList) {
    set<pair<int, int>> st; // Min-heap (sorted by distance)
    vector<int> dist(n + 1, INT_MAX); // Stores shortest distances

    // Initialize source
    dist[src] = 0;
    st.insert({0, src});

    while (!st.empty()) {
        pair<int, int> top = *st.begin();  // Fix for structured bindings issue
        int d = (int)top.first;
        int node = top.second;
        st.erase(st.begin());

        for (auto &nbr : adjList[node]) {
            int v = nbr.first;
            int weight = nbr.second;
            if (dist[node] + weight < dist[v]) { // Found a shorter path
                st.erase({dist[v], v}); // Remove old entry (if exists)
                dist[v] = dist[node] + weight;
                st.insert({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> edges = {{1, 2, 4}, {1, 3, 1}, {2, 3, 2}, {2, 4, 5}, {3, 4, 8}, {3, 5, 10}, {4, 5, 2}};

    int n = 5; // Number of nodes

    // Prepare adjacency list
    vector<vector<pair<int, int>>> adjList(n + 1);
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // Since graph is undirected
    }

    int src = 1; // Source node
    vector<int> shortestDist = dijkstra(src, n, adjList);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " : " << (shortestDist[i] == INT_MAX ? -1 : shortestDist[i]) << "\n";
    }

    return 0;
}
