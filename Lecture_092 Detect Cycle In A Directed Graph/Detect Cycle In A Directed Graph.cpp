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

    // Variable to count nodes processed
    int nodesProcessed = 0;

    // BFS
    while (!q.empty()) {
        int current = q.front();
        q.pop();
        nodesProcessed++;

        for (int neighbor : adjList[current]) {
            inDegree[neighbor]--;
            
            if (inDegree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    // If all nodes are processed, no cycle is present
    if (nodesProcessed == n) {
        return false;
    }

    // If there are remaining nodes, a cycle is present
    return true;
}

int detectCycleInDirectedGraph(int n, vector<pair<int, int>>& edges) {
    return detectCycleBFS(n, edges);
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