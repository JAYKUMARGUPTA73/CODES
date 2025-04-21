#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<int>> adjList;

    Graph(int n) {
        adjList.resize(n + 1);
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
    }

    // DFS for Topological Sort
    void dfs(int node, vector<int> &visited, stack<int> &topo) {
        visited[node] = 1;
        for (auto nbr : adjList[node]) {
            if (!visited[nbr]) {
                dfs(nbr, visited, topo);
            }
        }
        topo.push(node);
    }

    // DFS to find SCC in the reversed graph
    void dfs2(int node, vector<vector<int>> &revAdjList, vector<int> &visited, vector<int> &scc) {
        visited[node] = 1;
        scc.push_back(node);
        for (auto nbr : revAdjList[node]) {
            if (!visited[nbr]) {
                dfs2(nbr, revAdjList, visited, scc);
            }
        }
    }

    void findScc(int n) {
        stack<int> topo;
        vector<int> visited(n + 1, 0);

        // Step 1: Perform DFS to get the topological order
        for (int i = 0; i <= n; i++) {
            if (!visited[i]) {
                dfs(i, visited, topo);
            }
        }

        // Step 2: Reverse the graph
        vector<vector<int>> revAdjList(n + 1);
        for (int u = 0; u <= n; u++) {
            for (int v : adjList[u]) {
                revAdjList[v].push_back(u);
            }
        }

        // Step 3: Perform DFS on the reversed graph in the order of the topological sort
        fill(visited.begin(), visited.end(), 0);
        vector<vector<int>> ans;

        while (!topo.empty()) {
            int top = topo.top();
            topo.pop();

            if (!visited[top]) {
                vector<int> scc;
                dfs2(top, revAdjList, visited, scc);
                ans.push_back(scc);
            }
        }

        // Step 4: Print the strongly connected components
        for (auto &arr : ans) {
            cout << "{";
            for (size_t i = 0; i < arr.size(); i++) {
                cout << arr[i];
                if (i != arr.size() - 1) cout << ", ";
            }
            cout << "} ";
        }
    }
};

int main() {
    int n = 7;
    Graph obj(n);

    obj.addEdge(0, 1);
    obj.addEdge(1, 2);
    obj.addEdge(2, 3);
    obj.addEdge(3, 0);
    obj.addEdge(2, 4);
    obj.addEdge(4, 5);
    obj.addEdge(5, 6);
    obj.addEdge(6, 4);
    obj.addEdge(6, 7);

    obj.findScc(n);

    return 0;
}
