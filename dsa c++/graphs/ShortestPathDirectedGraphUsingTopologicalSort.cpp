#include<iostream>
#include<unordered_map>
#include<stack>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;

class Graph {
public:
    unordered_map<int, list<pair<int,int>>> adjList;

    void addEdge(int u, int v, int weight) {
        pair<int,int> p = make_pair(v, weight);
        adjList[u].push_back(p);
    }

    void printAdjList() {
        for(auto i : adjList) {
            cout << i.first << "-->";
            for(auto j : i.second) {
                cout << "[" << j.first << "," << j.second << "]";
            }
            cout << endl;
        }
    }

    void dfs(int node, vector<int> &isVisited, stack<int> &s) {
        isVisited[node] = 1;
        for(auto i : adjList[node]) {
            if(!isVisited[i.first]) {
                dfs(i.first, isVisited, s);
            }
        }
        s.push(node);
    }

    void getShortestPath(int src, vector<int> &d) {
        stack<int> s;
        vector<int> isVisited(adjList.size(), 0);

        // Perform DFS to get topological ordering
        for(auto i : adjList) {
            if(!isVisited[i.first]) {
                dfs(i.first, isVisited, s);
            }
        }

        // Initialize distances
        d[src] = 0;

        // Process vertices in topological order
        while(!s.empty()) {
            int top = s.top();
            s.pop();
            if(d[top] != INT_MAX) {
                for(auto i : adjList[top]) {
                    // Relaxation step
                    if(d[top] + i.second < d[i.first]) {
                        d[i.first] = d[top] + i.second;
                    }
                }
            }
        }
    }
};

int main() {
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    g.printAdjList();

    // Topological sort using DFS
    int n = g.adjList.size()+1; // Number of vertices in the graph
    vector<int> isVisited(n, 0);
    stack<int> s;

    // Perform DFS on all nodes
    for(int i = 0; i < n; i++) {
        if(!isVisited[i]) {
            g.dfs(i, isVisited, s);
        }
    }

    // Shortest path from source node 1 (adjust according to your graph)
    int src = 1;
    vector<int> d(n, INT_MAX);
    cout<<n<<endl;

    g.getShortestPath(src, d);

    cout << "Shortest distances from node " << src << ":\n";
    for(int i = 0; i < n; i++) {
        if(d[i] == INT_MAX) {
            cout << "INF ";
        } else {
            cout << d[i] << " ";
        }
    }
    cout << endl;
    cout<<d.size();

    return 0;
}
