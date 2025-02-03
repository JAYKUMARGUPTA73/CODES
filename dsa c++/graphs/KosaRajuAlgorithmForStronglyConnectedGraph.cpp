#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>

using namespace std;

void dfs2(int node, vector<int> &visited, unordered_map<int, list<int>> &transpose, vector<int> &component) {
    visited[node] = 1;
    component.push_back(node);
    for (auto nbr : transpose[node]) {
        if (!visited[nbr]) {
            dfs2(nbr, visited, transpose, component);
        }
    }
}

void dfs(int node, vector<int> &isVisited, stack<int> &s, unordered_map<int, list<int>> &adjList) {
    isVisited[node] = 1;
    for (auto nbr : adjList[node]) {
        if (!isVisited[nbr]) {
            dfs(nbr, isVisited, s, adjList);
        }
    }
    s.push(node);
}

vector<vector<int>> stronglyConnectedComponents(int v, vector<vector<int>> &edges) {
    // create adjList:
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        // directed graph
        adjList[u].push_back(v);
    }

    // find topo sort using DFS
    vector<int> isVisited(v, 0);
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!isVisited[i]) {
            dfs(i, isVisited, s, adjList);
        }
    }

    // transpose the graph
    unordered_map<int, list<int>> transpose;
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        transpose[v].push_back(u);
    }

    // do dfs via traversing the toposort
    vector<int> visited(v, 0);
    vector<vector<int>> sccs;
    vector<int> component;

    while (!s.empty()) {
        int node = s.top();
        s.pop();
        if (!visited[node]) {
            // New SCC found
            component.clear();
            dfs2(node, visited, transpose, component);
            sccs.push_back(component);
        }
    }
    return sccs;
}

int main() {
    // Example usage:
    int v = 8;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2},
        {2, 0},
        {2, 3},
        {3, 4},
        {4, 5},
        {5, 3},
        {6, 5},
        {6, 7},
        {7, 6}
    };

    vector<vector<int>> sccs = stronglyConnectedComponents(v, edges);
    cout << "Number of strongly connected components: " << sccs.size() << endl;

    // Print SCCs
    for (int i = 0; i < sccs.size(); i++) {
        cout << "SCC " << i + 1 << ": ";
        for (int j = 0; j < sccs[i].size(); j++) {
            cout << sccs[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
