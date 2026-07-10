#include <bits/stdc++.h>
using namespace std;

// GFG----> Topological Sort

vector<int> topoSort(int V, vector<vector<int>>& edges) {

    // Step 1: build adjacency list + indegree
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    for (auto edge: edges) {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);    // u -> v
        indegree[v]++;          // incoming edge for v
    }

    // Step 2: push nodes with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)   q.push(i);
    }

    // Step 3: BFS (Kahn's Algorithm)
    vector<int> ans;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);   // add to topo order

        for(int neigh : adj[node]){
                
            indegree[neigh]--;
            
            if(indegree[neigh] == 0)    q.push(neigh);
            
        }
    }

    return ans;
}



int main() {

    int V = 6;

    vector<vector<int>> edges = {
        {5, 2}, {5, 0},
        {4, 0}, {4, 1},
        {2, 3}, {3, 1}
    };

    vector<int> ans = topoSort(V, edges);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}