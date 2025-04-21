#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int src, int n, vector<vector<pair<int, int>>> &adjList) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);
    dist[src] = 0;
    pq.push({0, src}); // pair<distance, node val> 

    while (!pq.empty()) {
        auto front = pq.top();
        pq.pop();
        int d=front.first;
        int node=front.second;

        // Skip if we've already found a better path
        if (d > dist[node]) continue;

        for (auto &it : adjList[node]) {
            int weight=it.second;
            int nbr=it.first;
            if (dist[node] + weight < dist[nbr]) {
                dist[nbr] = dist[node] + weight;
                pq.push({dist[nbr], nbr});
            }
        }
    }

    return dist;
}

int main() {
    vector<vector<int>> edges = {{1, 2, 4}, {1, 3, 1}, {2, 3, 2}, {2, 4, 5}, {3, 4, 8}, {3, 5, 10}, {4, 5, 2}};
    int n = 5;

    vector<vector<pair<int, int>>> adjList(n + 1);
    for (auto &edge : edges) {
        int u = edge[0], v = edge[1], w = edge[2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    int src = 1;
    vector<int> shortestDist = dijkstra(src, n, adjList);

    cout << "Shortest distances from node " << src << ":\n";
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " : " << (shortestDist[i] == INT_MAX ? -1 : shortestDist[i]) << "\n";
    }

    return 0;
}
