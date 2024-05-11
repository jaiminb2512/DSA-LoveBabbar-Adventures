#include<bits/stdc++.h>
using namespace std;

void dfs(int node, vector<int>& visited, stack<int>& s, vector<vector<int>>& adjList) {
    visited[node] = 1;
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, s, adjList);
        }
    }
    s.push(node);
}

void dfs_reverse(int node, vector<int>& visited, vector<int>& component, vector<vector<int>>& revAdjList) {
    visited[node] = 1;
    component.push_back(node);
    for (int neighbor : revAdjList[node]) {
        if (!visited[neighbor]) {
            dfs_reverse(neighbor, visited, component, revAdjList);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>>& edges) {
    vector<vector<int>> adjList(v);
    vector<vector<int>> revAdjList(v);

    for (auto edge : edges) {
        int from = edge[0];
        int to = edge[1];
        adjList[from].push_back(to);
        revAdjList[to].push_back(from);
    }

    stack<int> s;
    vector<int> visited(v, 0);

    // First DFS to fill the stack
    for (int i = 0; i < v; ++i) {
        if (!visited[i]) {
            dfs(i, visited, s, adjList);
        }
    }

    // Reverse the edges in the graph
    vector<int> reverseVisited(v, 0);
    int countSCC = 0;

    while (!s.empty()) {
        int node = s.top();
        s.pop();

        if (!reverseVisited[node]) {
            vector<int> component;
            dfs_reverse(node, reverseVisited, component, revAdjList);
            // Process the strongly connected component as needed
            countSCC++;
        }
    }

    return countSCC;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int v, e;
        cin >> v >> e;

        vector<vector<int>> edges(e, vector<int>(2));

        for (int i = 0; i < e; ++i) {
            cin >> edges[i][0] >> edges[i][1];
        }

        int result = stronglyConnectedComponents(v, edges);
        cout << result << endl;
    }

    return 0;
}
