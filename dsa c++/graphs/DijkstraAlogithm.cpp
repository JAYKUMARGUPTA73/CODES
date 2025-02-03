#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <set>
#include <climits>

using namespace std;

vector<int> dijkstra(vector<vector<int>>& vec, int vertices, int edges, int source) {
    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;
    for (auto i : vec) {
        int u = i[0];
        int v = i[1];
        int w = i[2]; // corrected index for weight

        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w}); // for undirected graph
    }

    // Min-Heap to store vertices and their distances
    set<pair<int, int>> s;
    vector<int> d(vertices, INT_MAX); // distances from source
    d[source] = 0;
    s.insert({0, source});

    // Dijkstra's algorithm
    while (!s.empty()) {
        auto top = *s.begin();
        s.erase(s.begin());

        int u = top.second;

        for (auto j : adjList[u]) {
            int v = j.first;
            int weight = j.second;

            if (d[v] > d[u] + weight) {
                // Update distance if a shorter path is found
                s.erase({d[v], v}); // Remove old pair
                d[v] = d[u] + weight;
                s.insert({d[v], v}); // Insert updated pair
            }
        }
    }

    return d;
}

int main() {
    // Example usage
    int vertices = 7; // Number of vertices (0 to 6)
    int edges = 10;   // Number of edges
    vector<vector<int>> edgesList = {{0, 1, 4}, {0, 2, 8}, {1, 2, 11}, {1, 3, 8}, {2, 4, 7},
                                     {2, 5, 1}, {3, 4, 2}, {3, 6, 7}, {4, 6, 9}, {5, 6, 10}};
    int source = 0;   // Source node (starting from 0)

    vector<int> shortestDistances = dijkstra(edgesList, vertices, edges, source);

    // Output shortest distances from source
    cout << "Shortest distances from node " << source << ":\n";
    for (int i = 0; i < shortestDistances.size(); ++i) {
        cout << i << ": " << shortestDistances[i] << endl;
    }

    return 0;
}
