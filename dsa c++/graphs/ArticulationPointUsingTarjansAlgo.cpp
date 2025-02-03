#include <iostream>
#include<vector>
#include<unordered_map>
#include<list>
using namespace std;
void dfs(int node,int parent,int &timer,unordered_map<int,list<int>> &adjList,vector<int> &discovery,vector<int>  &low,vector<int> &visited,vector<int> &result){
    visited[node]=1;
    discovery[node]=low[node]=timer++;
    int child=0;
    for(auto nbr:adjList[node]){
        if(parent==nbr){
            //skip traversing back to parent to aviod looping back;
            continue;
        }
        if(!visited[nbr]){
            dfs(nbr,node,timer,adjList,discovery,low,visited,result);
            //returning back update the value of node 
            low[node]=min(low[node],discovery[nbr]);
            if((low[nbr]>=discovery[node])&&(parent!=-1)){
                result.push_back(node);
            }
            child++;

        }else{
            //visited means node has a back edge so we need update this node low based on discovetry of  neighbour
            low[node]=min(low[node],discovery[nbr]);

        }
    }
    if(parent==-1 && child>1){
        result.push_back(node);
    }

}

vector<int> findArticulationPoints(vector<vector<int>> &edges,int v){
    //create the AdjList
    unordered_map<int,list<int>> adjList;
    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        //undirected graph 
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> visited(v,0);
    vector<int> discovery(v,-1);
    vector<int> low(v,-1);
    int parent=-1;
    int src=0;
    int timer=0;

    vector<int> result;

    for(int i=0;i<v;i++){
        if(!visited[i]){
            dfs(i,parent,timer,adjList,discovery,low,visited,result);
        }
    }

    return result;
}
int main(){
    vector<vector<int>> edges={
        {0,3},
        {0,4},
        {0,1},
        {1,2},
        {1,0},
        {2,1},
        {3,0},
        {3,4},
        {4,0},
        {4,3}
    };
    
    int v=5;
    vector<int> result;
    result=findArticulationPoints(edges,v);
    cout<<"Articulation Points"<<endl;
    for(auto i:result){
        cout<<i<<" ";
    }
    return 0;
}