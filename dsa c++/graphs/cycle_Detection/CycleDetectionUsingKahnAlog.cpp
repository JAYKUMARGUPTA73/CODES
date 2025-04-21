#include<bits/stdc++.h>
using namespace std;
bool isCyclic(vector<vector<int>> &edges,int n){
    // kahns algo
    vector<int> indegree(n+1,0);
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        adjList[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    int cnt=0;
    while(!q.empty()){
        int frontNode=q.front();
        q.pop();
        cnt++;
        for(auto nbr:adjList[frontNode]){
            indegree[nbr]--;
            if (indegree[nbr] == 0) {
                q.push(nbr);
            }
        }
    }
    return cnt!=n;
}
int main(){
    vector<vector<int>> edges = {
        {1, 2}, {2, 3}, {4, 5}, {5, 6},
        {6, 8}, {8, 9}, {5, 7}
    };
    int n = 9;
    
    cout<<isCyclic(edges,n);
}