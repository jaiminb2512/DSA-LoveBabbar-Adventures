#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

bool detectCycleBFS(int n, vector<pair<int, int>>& edges) {
    unordered_map<int, vector<int>> adjList;
    vector<int> inDegree(n + 1, 0);

    // Create the adjacency list and calculate in-degrees
    for (const auto& edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    // Queue for BFS
    queue<int> q;

    // Push nodes with in-degree zero to the queue
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // BFS
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        for (int neighbor : adjList[current]) {
            inDegree[neighbor]--;
            
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If there are still edges remaining, a cycle is present
    for (int i = 1; i <= n; i++) {
        if (inDegree[i] > 0) {
            return true;
        }
    }

    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    return detectCycleBFS(n, edges);
}
