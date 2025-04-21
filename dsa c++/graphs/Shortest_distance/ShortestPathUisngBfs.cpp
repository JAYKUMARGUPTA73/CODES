#include<bits/stdc++.h>
using namespace std;
// it would work for directed as well as undirected both but they should be unwighted
// BFS for shortest path in an unweighted graph
vector<int> shortestPath(vector<pair<int,int>> &edges,int n,int s,int t){
    vector<vector<int>> adjList(n+1);
    for (auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // undirected graph
    }
    vector<int> parent(n+1,-1);
    vector<int> visited(n+1,0);
    // perform bfs and store parents during first visit as it will be the shortest 
    queue<int> q;
    visited[s]=1;

    q.push(s);
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        for(auto nbr:adjList[frontNode]){
            if(!visited[nbr]){
                parent[nbr]=frontNode;
                q.push(nbr);
                visited[nbr]=1;
            }
        }
    }
    vector<int> path;
    if (parent[t] == -1 && s != t) {
        return path;  // No path found
    }

    int curr = t;
    while (curr != -1) {
        path.push_back(curr);
        curr = parent[curr];
    }

    reverse(path.begin(), path.end());
    return path;
}
int main() {
    vector<pair<int, int>> edges = {{0, 1}, {0, 2}, {2, 3}, {2, 4}, {3, 5}, {4, 5}};
    int n=5;
    int s = 0; // Source node
    int t = 5; // Target node

    // Get the shortest path
    vector<int> path = shortestPath(edges, n, s, t);

    // Print the path
    if (!path.empty()) {
        cout << "Shortest path from " << s << " to " << t << ": ";
        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    } else {
        cout << "No path from " << s << " to " << t << " exists." << endl;
    }

    return 0;
}
