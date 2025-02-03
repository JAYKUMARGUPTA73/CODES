#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <set>
#include <list>
#include <climits>

using namespace std;

// Function to calculate MST using Prim's algorithm
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>>& g) {

    // Create adjacency list
    unordered_map<int, list<pair<int, int>>> adjList;
    for (auto& edge : g) {
        int u = edge.first.first;
        int v = edge.first.second;
        int w = edge.second;
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }

    vector<int> key(n + 1, INT_MAX);
    vector<int> parent(n + 1, -1);
    vector<int> mst(n + 1, 0);

    int src = 1;
    key[src] = 0;  // Start from source with key 0
    parent[src] = -1;

    // Prim's algorithm to find MST
    for (int count = 1; count <= n; ++count) {
        int frontNode = -1;
        // Find the vertex with the minimum key value which is not yet included in MST
        for (int i = 1; i <= n; ++i) {
            if (mst[i] == 0 && (frontNode == -1 || key[i] < key[frontNode])) {
                frontNode = i;
            }
        }

        mst[frontNode] = 1;  // Include the picked vertex in MST

        // Update key and parent values for adjacent vertices
        for (auto& neighbor : adjList[frontNode]) {
            int v = neighbor.first;
            int weight = neighbor.second;

            if (mst[v] == 0 && weight < key[v]) {
                parent[v] = frontNode;
                key[v] = weight;
            }

        }
    }

    // Prepare MST edges in the required format
    vector<pair<pair<int, int>, int>> ansList;
    for (int i = 2; i <= n; ++i) {
        int u = parent[i];
        int v = i;
        int w = key[i];
        ansList.push_back(make_pair(make_pair(u, v), w));
    }

    return ansList;
}

int main() {
    int n = 6;  // Number of vertices
    int m = 9;  // Number of edges

    // Example graph represented as vector of edges (pairs of pairs and weights)
    vector<pair<pair<int, int>, int>> edges = {
        {{1, 2}, 4},
        {{1, 6}, 2},
        {{2, 3}, 6},
        {{2, 6}, 1},
        {{3, 6}, 3},
        {{3, 4}, 5},
        {{4, 6}, 4},
        {{4, 5}, 2},
        {{5, 6}, 6}
    };

    // Calculate MST using Prim's algorithm
    vector<pair<pair<int, int>, int>> mstEdges = calculatePrimsMST(n, m, edges);

    // Output the MST edges and their weights
    cout << "Edges in the Minimum Spanning Tree:" << endl;
    for (auto& edge : mstEdges) {
        cout << edge.first.first << " - " << edge.first.second << " : " << edge.second << endl;
    }

    return 0;
}
