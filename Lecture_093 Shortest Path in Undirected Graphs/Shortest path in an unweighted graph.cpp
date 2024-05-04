#include <bits/stdc++.h>
using namespace std;

// Function to find the shortest path using BFS in an undirected graph
vector<int> shortestPath(vector<pair<int, int>>& edges, int n, int m, int src, int tar) {
    // Creating adjacency list
    unordered_map<int, list<int>> adjList;
    
    // Populate the adjacency list with edges
    for (int i = 0; i < n; i++) {
        int u = edges[i].first;
        int v = edges[i].second;

        adjList[u].push_back(v);
        adjList[v].push_back(u);  // Undirected graph, so adding both directions
    }

    // Arrays to keep track of visited nodes and their parents in the BFS traversal
    vector<int> visited(n, 0);
    vector<int> parent(n, 0);

    // Queue for BFS traversal
    queue<int> qu;

    // Initialize the BFS traversal from the source node
    qu.push(src);
    visited[src] = 1;
    parent[src] = -1;  // Parent of the source node is set to -1

    // BFS traversal
    while (!qu.empty()) {
        int val = qu.front();
        qu.pop();

        // Explore neighbors of the current node
        for (int x : adjList[val]) {
            if (visited[x] == 0) {
                visited[x] = 1;
                parent[x] = val;
                qu.push(x);
            }
        }
    }

    // Reconstruct the shortest path from target to source using the parent array
    vector<int> solution;
    while (tar != src) {
        solution.push_back(tar);
        tar = parent[tar];
    }
    solution.push_back(src);

    // Reverse the path to get it from source to target
    reverse(solution.begin(), solution.end());

    // Return the shortest path
    return solution;
}


int main() {
    vector< pair<int,int> > edges;
    int n, m, src, tar;

    cout << "Enter the number of nodes : ";
    cin >> n;
    
    cout << "Enter the number of edges : ";
    cin >> m;

    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u,v));
    }

    cout << "Enter the source and target : ";
    cin >> src >> tar;

    vector<int> answer = shortestPath(edges, n, m, src, tar);
    cout << "The shortest path : ";
    for(int x : answer) {
        cout << x << " ";
    }

    return 0;
}

// 8 9 0 1 0 2 0 3 1 4 2 7 3 5 5 6 6 7 4 7