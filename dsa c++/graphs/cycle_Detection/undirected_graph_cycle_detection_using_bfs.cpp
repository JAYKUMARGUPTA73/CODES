#include <bits/stdc++.h>
using namespace std;

bool bfs(int start, vector<vector<int>> &adjList, vector<int> &parent, vector<int> &isVisited) {
    queue<int> q;
    q.push(start);
    isVisited[start] = 1; // Mark start node as visited
    parent[start] = -1; // Start node has no parent

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int nbr : adjList[node]) {
            if (!isVisited[nbr]) { 
                parent[nbr] = node;
                isVisited[nbr] = 1;
                q.push(nbr);
            } else if (parent[node] != nbr) { 
                // If the neighbor is already visited and is not the parent of the current node, cycle detected
                return true;
            }
        }
    }
    return false;
}

bool isCyclic(vector<vector<int>> &adjList, int n) {
    vector<int> parent(n + 1, -1);
    vector<int> isVisited(n + 1, 0);

    for (int i = 1; i <= n; i++) {
        if (!isVisited[i]) {
            if (bfs(i, adjList, parent, isVisited)) 
                return true;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {6, 8}, {8, 9}, {5, 7}};
    
    int n = 9;
    vector<vector<int>> adjList(n + 1); // Adjusted to 1-based indexing

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << (isCyclic(adjList, n) ? "Graph contains a cycle" : "Graph does not contain a cycle") << endl;
}
