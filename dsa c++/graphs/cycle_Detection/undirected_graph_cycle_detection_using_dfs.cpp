#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adjList, int parent, vector<int> &isVisited)
{
    isVisited[node] = 1; // Mark node as visited

    for (auto nbr : adjList[node])
    {
        if (!isVisited[nbr])  // Explore unvisited neighbor
        {
            if (dfs(nbr, adjList, node, isVisited))
                return true;
        }
        else if (nbr != parent) // If neighbor is visited & not parent, cycle detected
        {
            return true;
        }
    }
    return false;
}

bool isCyclic(vector<vector<int>> &adjList, int n)
{
    vector<int> isVisited(n + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        if (!isVisited[i]) // Check each connected component
        {
            if (dfs(i, adjList, -1, isVisited))
                return true;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {2, 3}, {4, 5}, {5, 6}, {6, 8}, {8, 9}, {5, 7}};

    int n = 9;
    vector<vector<int>> adjList(n + 1); // 1-based indexing

    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    cout << (isCyclic(adjList, n) ? "Graph contains a cycle" : "Graph does not contain a cycle") << endl;
}
