#include <bits/stdc++.h>
using namespace std;

// Function to create adjacency list from edges
void createAdjList(vector<vector<int>> &edges, unordered_map<int, list<int>> &adjList) {
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
}

// Depth First Search function to assist topological sort2
void dfs(int node, unordered_map<int, list<int>> &adjList, vector<int> &isVisited, stack<int> &s) {
    isVisited[node] = 1;
    for (auto n : adjList[node]) {
        if (!isVisited[n]) {
            dfs(n, adjList, isVisited, s);
        }
    }
    s.push(node);
}

// Function to perform topological sort on a directed graph
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e) {
    unordered_map<int, list<int>> adjList;
    createAdjList(edges, adjList);
    vector<int> isVisited(v, 0);
    stack<int> s;
    for (int i = 0; i < v; i++) {
        if (!isVisited[i]) {
            dfs(i, adjList, isVisited, s);
        }
    }
    vector<int> ans;
    while (!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// Driver code to test the topologicalSort function
int main() {
    int v, e;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "Enter number of edges: ";
    cin >> e;
    
    vector<vector<int>> edges(e, vector<int>(2));
    cout << "Enter the edges (u v format, zero-indexed):\n";
    for (int i = 0; i < e; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    
    vector<int> result = topologicalSort(edges, v, e);
    
    cout << "Topological Sort of the given graph is:\n";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}
