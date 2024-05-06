// Step 1: Create Adjacency List
// Create an unordered map adjList to represent the adjacency list of the graph.
// Loop through each edge in the edges vector.
// Extract the source node (u), destination node (v), and weight (w) from the edge.
// Add an entry in the adjList for both u and v with a pair containing the destination node and weight.


// Step 2: Initialize Distance and Set
// Create a vector distance to store the shortest distances from the source to each node, initialized to INT_MAX.
// Create a set st to store pairs of distance and node. This set will be used to keep track of nodes with their current known distance.
// Set the distance of the source node (src) to 0.
// Insert a pair into the set (st) with distance 0 and the source node.


// Step 3: Dijkstra's Main Loop
// While the set (st) is not empty:
// Fetch the top pair (curr) from the set.
// Extract the current node's distance and Destination.
// Remove the top pair from the set.
// Iterate through neighbors of the current node (topNode).
// If the sum of the current distance and the edge weight to the neighbor is less than the known distance to the neighbor:
// Find and erase the old record of the neighbor in the set.
// Update the distance to the neighbor.
// Insert a new pair into the set with the updated distance and the neighbor's Destination.


// Step 4: Return Result
// Return the vector distance containing the shortest distances from the source node to all other nodes.


#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector< vector<int> > &edges, int n, int m, int src) {
    // Creating adj list
    unordered_map< int, list<pair<int,int>> > adjList;
    for(int i=0; i<m; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        adjList[u].push_back({v,w});
        adjList[v].push_back({u,w});
    }

    vector<int> distance(n,INT_MAX);
    set<pair<int,int>> st;

    distance[src] = 0;
    st.insert({0,src});

    while(!st.empty()) {
        // Fetching top pair
        pair<int,int> curr = *(st.begin());

        int nodeDistance = curr.first;
        int topNode = curr.second;

        // Removing top pair
        st.erase(st.begin());

        for(auto neigh : adjList[topNode]) {
            if(nodeDistance + neigh.second < distance[neigh.first]) {
                auto record = st.find({distance[neigh.first], neigh.first});

                // Erasing old record
                if(record != st.end()) {
                    st.erase(record);
                }

                // Upadting distance
                distance[neigh.first] = nodeDistance + neigh.second;
                
                // Inserting new pair in set
                st.insert({distance[neigh.first], neigh.first});
            }
        }
    }

    return distance;
}

int main() {
    vector<vector<int>> edges;
    int n, m, src;

    cout << "Enter the number of nodes : ";
    cin >> n;
    
    cout << "Enter the number of edges : ";
    cin >> m;

    cout << "Enter the edges : " << endl;
    for(int i=0; i<m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u,v,w});
    }

    cout << "Enter the source : ";
    cin >> src;

    vector<int> answer = shortestPath(edges, n, m, src);
    cout << "The shortest path : ";
    for(int x : answer) {
        cout << x << " ";
    }

    return 0;
}

// 4 5 0 1 5 1 2 9 1 3 2 2 3 6 0 2 8
// 5 7 2 1 3 1 4 1 0 3 2 2 0 1 1 0 7 1 3 5 3 4 7