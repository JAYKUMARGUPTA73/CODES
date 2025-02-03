#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(vector<int>& a, vector<int>& b) {
    return a[2] < b[2];
}

int findParent(int node, vector<int>& parent) {
    if (parent[node] != node) {
        parent[node] = findParent(parent[node], parent); // Path compression
    }
    return parent[node];
}

void makeSet(vector<int>& parent, vector<int>& rank) {
    for (int i = 0; i < parent.size(); i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

void unionSet(int u, int v, vector<int>& parent, vector<int>& rank) {
    // rootU is parent of curent u also parent[rootU] will be itself too so to update parentof rootU we can use parent[rootU];
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    
    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            //uopdate the parent(parent[rootU]) of smaller tree node to child of parent of larger tree
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

int minWeightMinimumSpanningTree(vector<vector<int>>& edges, int n) {
    vector<int> parent(n);
    vector<int> rank(n);
    makeSet(parent, rank);
    sort(edges.begin(), edges.end(), comparator);
    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0] - 1;  // Adjust for 0-indexing
        int v = edges[i][1] - 1;  // Adjust for 0-indexing
        int w = edges[i][2];
        
        if (findParent(u, parent) != findParent(v, parent)) {
            unionSet(u, v, parent, rank);
            minWeight += w;
        }
    }
    return minWeight;
}

int main() {
    int n = 6;  // Number of vertices
    vector<vector<int>> edges = {
        {1, 2, 4},
        {1, 6, 2},
        {2, 3, 6},
        {2, 6, 1},
        {3, 6, 3},
        {3, 4, 5},
        {4, 6, 4},
        {4, 5, 2},
        {5, 6, 6}
    };
    int minWeight = minWeightMinimumSpanningTree(edges, n);
    cout << "Minimum Spanning Tree Weight: " << minWeight << endl;
    return 0;
}