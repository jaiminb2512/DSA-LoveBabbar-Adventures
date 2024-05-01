#include <bits/stdc++.h> 
using namespace std;

vector<int> topologicalSort(vector<vector<int>>& edges, int v, int e) {
    vector<int> inDegree(v, 0);
    vector<vector<int>> adjList(v, vector<int>());

    // Create the adjacency list and calculate in-degrees
    for (const auto& edge : edges) {
        int u = edge[0];
        int v = edge[1];
        adjList[u].push_back(v);
        inDegree[v]++;
    }

    // Queue for BFS
    queue<int> q;

    // Push nodes with in-degree zero to the queue
    for (int i = 0; i < v; i++) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> result;
    
    // BFS
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        result.push_back(current);

        for (int neighbor : adjList[current]) {
            inDegree[neighbor]--;
            
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    return result;
}

int main() {
    vector< vector<int> > edges;
    int n, m;

    cout << "Enter number of nodes : ";
    cin >> n;

    cout << "Enter number of edges : ";
    cin >> m;

    cout << "Enter edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back({u,v});
    }

    vector<int> topSort = topologicalSort(edges, n, m);

    cout << "Topological Sort : ";
    for(int x : topSort) {
        cout << x << " ";
    }

    return 0;
}

// 4 4 0 1 1 2 0 3 3 2
// 6 7 0 1 0 2 1 3 2 3 3 4 3 5 4 5