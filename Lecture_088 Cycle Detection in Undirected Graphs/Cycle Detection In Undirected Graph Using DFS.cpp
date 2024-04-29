#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool dfs(int current, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[current] = true;

    for (int neighbor : adj[current]) {
        if (!visited[neighbor]) {
            if (dfs(neighbor, current, adj, visited)) {
                return true;
            }
        } else if (neighbor != parent) {
            return true;
        }
    }

    return false;
}

string cycleDetection(vector<vector<int>>& edges, int n, int m) {
    vector<vector<int>> adj(n + 1); // Adjacency list
    vector<bool> visited(n + 1, false);

    // Constructing the adjacency list
    for (int i = 0; i < m; ++i) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Check for cycles in each connected component
    for (int i = 1; i <= n; ++i) {
        if (!visited[i] && dfs(i, -1, adj, visited)) {
            return "Yes";
        }
    }

    return "No";
}