#include <bits/stdc++.h>
using namespace std;
// it would work for directed as well as undirected both but they should be unwighted
// BFS for shortest path in an unweighted graph
void bfs(int start, vector<vector<int>> &adjList, vector<int> &parent)
{
    queue<int> q;
    q.push(start);
    vector<int> visited(adjList.size(), 0);
    visited[start] = 1;
    parent[start] = -1; // Start node has no parent

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        for (auto nbr : adjList[node])
        {
            if (!visited[nbr])
            {
                visited[nbr] = 1;
                parent[nbr] = node;
                q.push(nbr);
            }
        }
    }
}

int main()
{
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {1, 4}, {2, 5}, {3, 8}, {4, 6}, {5, 8}, {6, 7}, {7, 8}};
    int n = 8;

    // Prepare adjacency list
    vector<vector<int>> adjList(n + 1);
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    vector<int> parent(n + 1, -1); // To track the path
    int start, end;
    cout << "Enter starting node: ";
    cin >> start;
    cout << "Enter ending node: ";
    cin >> end;

    // Find shortest path using BFS
    bfs(start, adjList, parent);

    // Reconstruct the path
    if (parent[end] == -1)
    {
        cout << "No path exists between " << start << " and " << end << endl;
        return 0;
    }

    vector<int> path;
    for (int node = end; node != -1; node = parent[node])
    {
        path.push_back(node);
    }
    reverse(path.begin(), path.end());

    // Print path
    cout << "Shortest path: ";
    for (int i = 0; i < (int)path.size(); i++)
    {
        cout << path[i];
        if (i < (int)path.size() - 1)
            cout << " -> ";
    }
    cout << endl;

    return 0;
}
