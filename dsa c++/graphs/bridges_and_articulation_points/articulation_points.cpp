#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    int time;                         // Global time counter for discovery times
    vector<int> parent;               // Stores parent of each node in DFS tree
    vector<int> low;                  // Lowest discovery time reachable from the subtree rooted at the node
    vector<int> disc;                 // Discovery time of each node
    vector<int> visited;              // Marks whether a node has been visited

    vector<vector<int>> adjList;      // Adjacency list representation of the graph
    set<int> articulationPoints;      // Set to store unique articulation points

    // Constructor to initialize graph with 'n' nodes
    Graph(int n) {
        time = 0;
        parent.resize(n + 1, -1);     // Initialize parent of all nodes as -1
        low.resize(n + 1, -1);        // Initialize low values as -1
        disc.resize(n + 1, -1);       // Initialize discovery times as -1
        visited.resize(n + 1, 0);     // Mark all nodes as unvisited
        adjList.resize(n + 1);        // Resize adjacency list
    }

    // Function to add an undirected edge between nodes u and v
    void addEdge(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

// written by me
    void dfs(int node){
        visited[node]=1;
        low[node]=disc[node]=++time;
        int children=0;
        for(auto nbr:adjList[node]){
            if(!visited[nbr]){
                parent[nbr]=node;
                children++;
                dfs(nbr);

                low[node]=min(low[node],low[nbr]);

                // u have trvesrsed the neighbours and still don't get its low time
                // to be less then disc time of curr node means there is no backedge
                // and only on edge exist so its a articulation point

                // basically linear increase of low time time shows no backedge
                if(parent[node]!=-1&&low[nbr]>=disc[node]){
                    articulationPoints.insert(node);
                }
            }else if(parent[node]!=nbr){
                low[node]=min(low[node],disc[nbr]);
            }
        }
        if(parent[node]==-1 && children>1){
            articulationPoints.insert(node);
        }
    }

    // Depth-First Search to find articulation points
    // void dfs(int node) {
    //     int childrens = 0;            // Count of children in DFS tree
    //     visited[node] = 1;            // Mark the current node as visited
    //     low[node] = disc[node] = ++time;  // Initialize discovery time and low value

    //     for (auto nbr : adjList[node]) {  // Explore all adjacent vertices
    //         if (!visited[nbr]) {          // If neighbor hasn't been visited
    //             parent[nbr] = node;       // Set parent of neighbor
    //             childrens++;              // Increment child count
    //             dfs(nbr);                 // Recursive DFS call

    //             // Update low value of current node based on child's low value
    //             low[node] = min(low[node], low[nbr]);

    //             // Condition for articulation point (non-root case)
    //             if (parent[node] != -1 && low[nbr] >= disc[node]) {
    //                 articulationPoints.insert(node);
    //             }
    //         }
    //         // Update low value if there's a back edge (excluding the parent edge)
    //         else if (nbr != parent[node]) {
    //             low[node] = min(low[node], disc[nbr]);
    //         }
    //     }

    //     // Condition for articulation point (root case)
    //     if (parent[node] == -1 && childrens > 1) {
    //         articulationPoints.insert(node);
    //     }
    // }

    // Function to find articulation points in the graph
    void findArticulationPoints(int n) {
        for (int i = 1; i <= n; i++) {     // Check for disconnected components
            if (!visited[i]) {
                dfs(i);
            }
        }

        // Display articulation points
        if (articulationPoints.empty()) {
            cout << "No articulation points found." << endl;
        } else {
            cout << "Articulation Points: ";
            for (int ap : articulationPoints) {
                cout << ap << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph g(5);                    // Create a graph with 5 nodes
    g.addEdge(1, 2);               // Add edges
    g.addEdge(1, 3);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);

    g.findArticulationPoints(5);   // Find and print articulation points

    return 0;
}
