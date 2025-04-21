#include<bits/stdc++.h>
using namespace std;
bool dfs(int node,vector<int> &dfsVisited,vector<int> &visited,vector<vector<int>> &adjList){
    visited[node]=1;
    dfsVisited[node]=1;
    for(auto nbr:adjList[node]){
        if(!visited[nbr]){
            if(dfs(nbr,dfsVisited,visited,adjList)){
                return true;
            }
        }else{
            if(dfsVisited[nbr]){
                return true;
            }
        }
    }
    dfsVisited[node]=0;
    return false;
}
bool detectCycleInDirectedGraph(int n,vector<pair<int,int>> &edges){
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<edges.size();i++){
        int u=edges[i].first;
        int v=edges[i].second;
        adjList[u].push_back(v);
    }
    vector<int> dfsVisited(n+1,0);
    vector<int> visited(n+1,0);
    for(int i=1;i<=n;i++){
        if(dfs(i,dfsVisited,visited,adjList)){
            return true;
        }
    }
    return false;
}
int main() {
    // Test case 1: Graph with a cycle (true)
    vector<pair<int,int>> edges1 = {{1, 2}, {2, 3}, {3, 4}, {4, 2}};
    int n1 = 4;
    bool hasCycle1 = detectCycleInDirectedGraph(n1, edges1);
    cout << "Test case 1 (with cycle): " << (hasCycle1 ? "true" : "false") << endl;

    // Test case 2: Graph without a cycle (false)
    vector<pair<int, int>> edges2 = {{1, 2}, {2, 3}, {3, 4}};
    int n2 = 4;
    bool hasCycle2 = detectCycleInDirectedGraph(n2, edges2);
    cout << "Test case 2 (without cycle): " << (hasCycle2 ? "true" : "false") << endl;

    return 0;
}