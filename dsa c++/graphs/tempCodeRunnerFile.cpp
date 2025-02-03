#include<iostream>
#include<vector>
#include<algorithm>
bool comparator(vector<int> &a,vector<int> &b){
    return a[2]<b[2];
}
int findParent(int node,vector<int> &parent){
    if(parent[node]!=node){
        return node;
    }
    return parent[node]=findParent(node,parent);
}
void makeSet(vector<int> &parent,vector<int> &rank){
    for(int i=0;i<parent.size();i++){
        parent[i]=i;
        rank[i]=0;
    }
}
void unionSet(int u,int v,vector<int>& parent,vector<int> &rank){
    u=findParent(u,parent);
    v=findParent(v,parent);
    if(rank[u]<rank[v]){
        parent[u]=v;
    }else if(rank[v]<rank[u]){
        parent[v]=u;
    }
    else{
        parent[u]=v;
        rank[v]++;
    }

}
int minWeightMinimumSpanningTree(vector<vector<int>> &edges,int n){
    vector<int> rank(n);
    vector<int> parent(n);
    makeSet(parent,rank);

    sort(edges.begin(),edges.end(),comparator);

    int minWeight=0;

    for(int i=0;i<n;i++){
        int u=findParent(edges[i][0],parent);
        int v=findParent(edges[i][1],parent);
        int w=edges[i][2];
        //if(u!=v) means u and v are from different comp so we need to add this edge;
        //we will add edge with minm weight keeping depth of tree to be minimum by using rank
        if(u!=v){
            //union set
            unionSet(u,v,parent,rank);
            minWeight+=w;
        }
    }
    return minWeight;
}

int main() {
    int n = 6;  // Number of vertices
    vector<vector<int>> edges = {
        {1, 2, 4},
        {1, 6, 2},
        {2, 3, 6},
        {2, 6, 1},
        {3, 6, 3},
        {3, 4, 5},
        {4, 6, 4},
        {4, 5, 2},
        {5, 6, 6}
    };

    int minWeight = minWeightMinimumSpanningTree(edges, n);

    cout << "Minimum Spanning Tree Weight: " << minWeight << endl;

    return 0;
}