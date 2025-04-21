#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    vector<vector<pair<int, int>>> adjList;
    Graph(int n)
    {
        adjList.resize(n + 1);
    }
    void addEdge(int u, int v, int w)
    {
        adjList[u].push_back({v, w});
        ;
    }

    vector<int> bellManFord(int n, vector<vector<pair<int, int>>> &adjList)
    {

        // run for n-1 times;
        int src = 1;
        vector<int> dis(n + 1, INT_MAX);
        dis[src] = 0;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 1; j <= n; j++)
            {

                // traverse to each nbr of node and update its weight
                for (auto nbr : adjList[j])
                {
                    int u = j;
                    int v = nbr.first;
                    int w = nbr.second;

                    // check for any updation
                    if (dis[u] + w < dis[v])
                    {
                        dis[v] = dis[u] + w;
                    }
                }
            }
        }

        // check for one more time
        int flag = 0;
        for (int j = 1; j <= n; j++)
        {

            // traverse to each nbr of node and update its weight
            for (auto nbr : adjList[j])
            {
                int u = j;
                int v = nbr.first;
                int w = nbr.second;

                // check for any updation
                if (dis[u] + w < dis[v])
                {
                    flag = 1;
                    dis[v] = dis[u] + w;
                }
            }
        }

        if(flag==1){
            cout<<"Negative weight cycle detected"<<endl;
            return {};
        }
        cout<<"Shortest distance"<<endl;
        for(int i=1;i<=n;i++){
            cout<<dis[i]<<" ";
        }
        return dis;
    }
};
int main()
{
    vector<vector<int>> edges = {{1, 2, 2}, {2, 3, -1}, {1, 3, 2}};
    int n = 3;
    Graph g1 = Graph(n);
    for (int i = 0; i < (int)edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        g1.addEdge(u, v, w);
    }
    g1.bellManFord(n,g1.adjList);
}