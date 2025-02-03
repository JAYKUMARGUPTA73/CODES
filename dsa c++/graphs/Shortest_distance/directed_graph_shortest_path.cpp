#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<pair<int,int>>> &adjList,vector<int> &isVisited,stack<int> &topo){
    isVisited[node]=1;
    for(auto nbr:adjList[node]){
        int v=nbr.first;
        int w=nbr.second;
        if(!isVisited[v]){
            dfs(v,adjList,isVisited,topo);
        }
    }
    topo.push(node);
}
int main()
{
    vector<vector<int>> edges = {{0, 1, 5}, {0, 2, 3}, {1, 3, 6}, {1, 2, 2}, {2, 3, 7}, {2, 4, 4}, {2, 5, 2}, {3, 4, -1}, {4, 5, -2}};

    // prepare adjList
    int n=5;
    vector<vector<pair<int,int>>> adjList(n+1);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        adjList[u].push_back({v,w});
    }

    // find topo sort using dfs
    stack<int> topo;
    vector<int> isVisited(n+1);
    for(int i;i<n;i++){
        if(!isVisited[i]){
            dfs(i,adjList,isVisited,topo);
        }
    }

    // 
    
    // process complete topo order and update the weights
    vector<int> distance(n+1,INT_MAX);
    distance[topo.top()]=0;
    cout<<"Topo sort"<<endl;
    while (!topo.empty())
    {
        int top=topo.top();
        cout<<top<<" ";
        topo.pop();
        for(auto nbr:adjList[top]){
            int v=nbr.first;
            int w=nbr.second;
            if(distance[top]+w<distance[v]) distance[v]=distance[top]+w;
        }
    }
    cout<<endl;
    cout<<"shortest distance vector"<<endl;

    for(auto num:distance){
        cout<<num<<" ";
    }
    

}