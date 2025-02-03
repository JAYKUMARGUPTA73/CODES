#include <bits/stdc++.h>
using namespace std;
class kruskals_algorithm
{
public:
    vector<int> rank, parent;
    // constructor
    kruskals_algorithm(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);

        // make every node parent of themselves
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
        cout << "Initial rank and parent array" << endl;
        cout << "Parent Array : ";
        for (int num : parent)
        {
            cout << num << " ";
        }
        cout << endl;
        cout << "Rank Array :";
        for (int num : rank)
        {
            cout << num << " ";
        }
    }

    int findParent(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = findParent(parent[x]);
        }
        return parent[x];
    }
    void unionSet(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;

        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            // increase rank of child
            rank[pv]++;
        }
        cout << endl;
        cout << "-----------------------------" << endl;
        cout << "-----------------------------" << endl;
        cout << "union (" << u << "," << v << ")" << endl;
        cout << endl;
        cout << "Parent Array : ";
        for (int num : parent)
        {
            cout << num << " ";
        }
        cout << endl;
        cout << "Rank Array :";
        for (int num : rank)
        {
            cout << num << " ";
        }
        cout << endl;
    }
};

int kruskals_main_algo(int n, vector<vector<int>> &edges)
{
    kruskals_algorithm obj = kruskals_algorithm(n);
    int mstWeight = 0;

    // SORT EDEGES BASED ON THEIR WEIGHT
    sort(edges.begin(), edges.end());
    for (auto num : edges)
    {
        int u = num[1];
        int v = num[2];
        int w=num[0];
        int pu = obj.findParent(u);
        int pv = obj.findParent(v);
        if (pu != pv)
        {
            mstWeight+=w;
            obj.unionSet(u, v);
        }
    }
    cout << "minimum spanning tree" << endl;
    for (int i = 0; i < n; i++)
    {
        if (obj.parent[i] != i)
        {
            cout << i << "->" << obj.parent[i] << endl;
        }
    }
    return mstWeight;
}

int main()
{
    vector<vector<int>> edges = {
        {2, 0, 1}, {3, 1, 2}, {7, 2, 4}, {5, 4, 1}, {8, 1, 3}, {6, 0, 3}};
    int n = 5;
    int ans=kruskals_main_algo(n,edges);
    cout<<"minimum spanning tree weight : "<< ans;
}