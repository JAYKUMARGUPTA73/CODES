#include <bits/stdc++.h>
using namespace std;

void createAdjList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList) {
    for(int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adjList;
    createAdjList(edges, adjList);

    vector<int> inDegree(v, 0);
    for(int i = 0; i < edges.size(); i++) {
        int v = edges[i][1];
        inDegree[v]++;
    }

    queue<int> q;
    for(int i = 0; i < v; i++) {
        if(inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> topoOrder;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);

        for(auto neighbor : adjList[node]) {
            inDegree[neighbor]--;
            if(inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    if(topoOrder.size() != v) {
        throw invalid_argument("The graph has a cycle, so topological sorting is not possible.");
    }

    return topoOrder;
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 3}, {2, 3}, {3, 4}};
    int v = 5;
    int e = edges.size();

    try {
        vector<int> topoOrder = topologicalSort(edges, v, e);
        cout << "Topological Sort Order: ";
        for(int node : topoOrder) {
            cout << node << " ";
        }
        cout << endl;
    } catch (const invalid_argument &e) {
        cout << e.what() << endl;
    }

    return 0;
}
