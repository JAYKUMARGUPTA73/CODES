#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int dfs(int node, int parent, unordered_map<int, vector<pair<int, int>>>& graph) {
    int x = 0;
    for (auto& neighbor : graph[node]) {
        int next_node = neighbor.first;
        int direction = neighbor.second;
        if (next_node == parent) continue;
        if (direction == 1) x++;
        x += dfs(next_node, node, graph);
    }
    return x;
}

int solution(vector<int>& A, vector<int>& B) {
    int n = A.size();
    unordered_map<int, vector<pair<int, int>>> g;

   
    for (int i = 0; i < n; ++i) {
        int u = A[i], v = B[i];
        g[u].emplace_back(v, 1); 
        g[v].emplace_back(u, 0);
    }

    return dfs(0, -1, g);
}

