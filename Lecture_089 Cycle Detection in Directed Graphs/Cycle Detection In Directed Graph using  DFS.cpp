// Comments

// Logic of isCyclicDFS
// visited is used to mark nodes as visited.
// dfsVisited is used to keep track of visited nodes during the current DFS traversal.
// For each neighbor of the current node, the function recursively calls itself if the neighbor is not visited.
// If a neighbor is already visited and is in the current DFS traversal (dfsVisited), it indicates the presence of a cycle.

#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

using namespace std;

bool isCyclicDFS(unordered_map<int, list<int>> &adjList, vector<int> &visited, vector<int> &dfsVisited, int node) {
    visited[node] = dfsVisited[node] = 1;

    for (int neighbor : adjList[node]) {
        if (visited[neighbor] == 0) {
            if (isCyclicDFS(adjList, visited, dfsVisited, neighbor)) {
                return true;
            }
        } else if (dfsVisited[neighbor] == 1) {
            return true;
        }
    }

    dfsVisited[node] = 0;
    return false;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges) {
    unordered_map<int, list<int>> adjList;

    for (const auto &edge : edges) {
        int u = edge.first;
        int v = edge.second;
        adjList[u].push_back(v);
    }

    vector<int> visited(n, 0);
    vector<int> dfsVisited(n, 0);

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            if (isCyclicDFS(adjList, visited, dfsVisited, i)) {
                return true;
            }
        }
    }

    return false;
}

int main() {
    vector< pair<int,int> > edges;
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

    bool answer = detectCyclicInDirectedGraph(n, edges);

    if(answer) {
        cout << "Cycle is Present" << endl;
    } else {
        cout << "Cycle is Not Present" << endl;
    }

    return 0;
}

// 8 9 0 1 1 2 2 6 2 7 7 6 1 3 3 4 4 5 5 3 - YES
// 8 9 0 1 1 2 2 6 2 7 7 6 1 3 3 4 4 5 3 5 - NO


// Differences from Directed Graphs:

// The graph is undirected, so the adjacency list is constructed for both directions (u to v and v to u).
// The dfs function checks for cycles by keeping track of the parent node to avoid considering the immediate parent as part of a cycle.
// The traversal checks for cycles in each connected component separately.
// In contrast, for directed graphs:

// Edges are directed, and the adjacency list is constructed based on the direction of edges.
// Cycles in directed graphs are detected by checking if a node is already in the recursion stack during DFS to identify back edges.

