#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<pair<int, int>>> adjList;

    Graph(int n) {
        adjList.resize(n + 1);
    }

    void addEdge(int u, int v, int w) {
        adjList[u].push_back({v, w});
    }

    void dfs(int node, vector<int> &visited, stack<int> &st) {
        visited[node] = 1;
        for (auto it : adjList[node]) {
            int nbr = it.first;
            if (!visited[nbr]) {
                dfs(nbr, visited, st);
            }
        }
        st.push(node);
    }

    void getShortestDistance(int n) {
        stack<int> st;
        vector<int> visited(n + 1, 0);

        for (int i = 0; i <= n; i++) {
            if (!visited[i]) {
                dfs(i, visited, st);
            }
        }

        vector<int> dist(n + 1, INT_MAX);
        int src = 0;
        dist[src] = 0;

        while (!st.empty()) {
            int front = st.top();
            st.pop();

            if (dist[front] != INT_MAX) {
                for (auto it : adjList[front]) {
                    int nbr = it.first;
                    int w = it.second;
                    if (dist[front] + w < dist[nbr]) {
                        dist[nbr] = dist[front] + w;
                    }
                }
            }
        }

        // Output the distances
        cout << "Shortest distances from node " << src << ":\n";
        for (int i = 0; i <= n; i++) {
            if (dist[i] == INT_MAX)
                cout << i << ": INF\n";
            else
                cout << i << ": " << dist[i] << "\n";
        }
    }
};

int main() {
    int n = 6;  // nodes are 0 to 5
    Graph g(n);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.getShortestDistance(n);
    return 0;
}
