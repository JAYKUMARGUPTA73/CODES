#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    vector<int> visited;
    vector<vector<int>> adjList;
    vector<vector<int>> ans;
    vector<int> isScc;
    Graph(int n)
    {
        visited.resize(n + 1, 0);
        adjList.resize(n + 1);
        isScc.resize(n + 1, 0);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
    }

    bool dfs(int node, int des, vector<int> &visited)
    {
        visited[node] = 1;
        if (node == des)
        {
            return true;
        }
        for (auto nbr : adjList[node])
        {
            if (!visited[nbr])
            {
                if (dfs(nbr, des, visited))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isPath(int u, int v)
    {
        vector<int> visited(adjList.size(), 0);  // Reset visited for each path check
        return dfs(u, v, visited);
    }

    void findScc(int n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!isScc[i])
            {
                vector<int> scc;
                scc.push_back(i);
                for (int j = i + 1; j <= n; j++)
                {
                    if (!isScc[j] && isPath(i, j) && isPath(j, i))
                    {
                        scc.push_back(j);
                        isScc[j] = 1; // Mark as visited in SCC
                    }
                }
                ans.push_back(scc);
                isScc[i] = 1; // Mark the current node as visited in SCC
            }
        }

        for (auto &num : ans)
        {
            cout << "{";
            for (auto &i : num)
            {
                cout << i << " ";
            }
            cout << "} ";
        }
    }
};

int main()
{
    int n = 7;
    Graph obj = Graph(n);
    obj.addEdge(1, 2);
    obj.addEdge(2, 4);
    obj.addEdge(2, 3);
    obj.addEdge(4, 1);
    obj.addEdge(4, 5);
    obj.addEdge(3, 4);
    obj.addEdge(3, 6);
    obj.addEdge(6, 7);
    obj.addEdge(7, 5);
    obj.addEdge(5, 6);

    obj.findScc(7);
}
