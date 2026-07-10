#include <bits/stdc++.h>
using namespace std;

// leetcode Q->75  IS Graph Bipartite?
// GFG-->Bipartite Graph

// But on GFG we hvae given the edges , so  
// first we have to convevrt those edges into adjacency listthen same leetcode code



bool isBipartite(int V, vector<vector<int>>& edges) {
    
    // Convert edge list → adjacency list
    vector<vector<int>> adj(V);
    
    for (auto &e : edges) {   // use reference (slightly better)
        int u = e[0];
        int v = e[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int n = V;


    
    // color[i] = -1 -> not visited
    // color[i] = 0 or 1 -> two different sets
    vector<int> color(n, -1);
    
    // Graph may be disconnected
    for (int i = 0; i < n; i++) {
        
        if (color[i] != -1)     continue;   // If already colored, skip
        
        // Start BFS
        queue<int> q;
        q.push(i);
        
        // Initial color
        color[i] = 0;
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            
            // Traverse neighbors
            for (int neigh : adj[node]) {
                
                // If not colored
                if (color[neigh] == -1) {
                    
                    color[neigh] = 1 - color[node];     // Assign opposite color
                    
                    q.push(neigh);
                }
                
                // Same color → not bipartite
                else if (color[neigh] == color[node])       return false;
            }

        }


    }
    
    return true;
}



int main() {
    int V = 3;
    
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2}
    };
    
    if (isBipartite(V, edges)) cout << "Yes, it is Bipartite\n";
    else cout << "NO\n";
    
    return 0;
}