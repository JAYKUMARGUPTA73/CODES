#include <bits/stdc++.h>
using namespace std;

// For a disconnected undirected graph, the definition is similar, a bridge is an edge removal that increases the number of disconnected components
// Brute force approach
// One by one remove all edges and see if the removal of an edge causes a disconnected graph. 
// optimal approach: Tarjan's algorithm
// Suppose there exists an edge from u -> v, now after removal of this edge if v can’t be reached by any other edges then u -> v edge is bridge

class Graph {
public:
    vector<int> visited;

    vector<int> disc;  // discovery time: keeps record of when for the first time 
                       // a particular node is being travelled

    vector<int> low;   // low time: keeps record of lowest time in which we can
                       // reach to any node without passing through node's parent 

    vector<int> parent;
    vector<vector<int>> adjList;
    int time; // Global timer to track discovery times

    Graph(int n) {
        visited.resize(n + 1, 0);
        low.resize(n + 1, -1);
        disc.resize(n + 1, -1);
        parent.resize(n + 1, -1); // Initialize parent with -1
        adjList.resize(n + 1);
        time = 0; // Initialize time counter
    }

    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    void bridge_dfs(int node, vector<vector<int>>& adjList, vector<int>& visited, vector<int>& parent, vector<int>& low, vector<int>& disc) {
        visited[node] = 1;
        disc[node] = low[node] = ++time;  // Assign discovery time and low time

        for (auto v : adjList[node]) {
            // case-i: if v is parent of node
            if (v == parent[node]) {
                continue;
            }
            // case-ii: if v is already visited, there might be chances of a lower
            // possible time to get to that node whose neighbors we are exploring
            if (visited[v]) {
                low[node] = min(low[node], disc[v]); // Update low time through back edge
            } else {
                // traverse recursively
                parent[v] = node;
                bridge_dfs(v, adjList, visited, parent, low, disc);
                low[node] = min(low[node], low[v]); // Update low value after recursion

                // Bridge condition
                if (low[v] > disc[node]) {
                    cout << node << "->" << v << endl; // Found a bridge
                }
            }
        }
    }

    void findBridges() {
        for (int i = 0; i < adjList.size(); i++) {
            if (!visited[i]) {
                bridge_dfs(i, adjList, visited, parent, low, disc);
            }
        }
    }
};

int main() {
    int n = 6;
    Graph g1 = Graph(n);

    cout<<"Bridges in graph are :"<<endl;
    g1.addEdge(1, 0);
    g1.addEdge(0, 2);
    g1.addEdge(2, 1);
    g1.addEdge(0, 3);
    g1.addEdge(3, 4);
    g1.findBridges();

    cout<<"Bridges in graph are :"<<endl;
    Graph g2=Graph(5);
    g2.addEdge(0, 1);
    g2.addEdge(1, 2);
    g2.addEdge(2, 3);
    g2.addEdge(3, 4);
    g2.findBridges();


    return 0;
}
