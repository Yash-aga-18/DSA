#include <bits/stdc++.h>
using namespace std;

// GFG----> Topological Sort


// -------- DFS HELPER --------
void dfs(int node, vector<vector<int>> &adj, vector<int> &vis, stack<int> &st) {

    vis[node] = 1;

    for (int neigh : adj[node] ) {

        if (vis[neigh] == 0)    dfs(neigh, adj, vis, st);
        
    }

    st.push(node);   // push after visiting all neighbors
}


// -------- DFS TOPO --------
vector<int> topoSortDFS(int V, vector<vector<int>> &edges) {

    // build adjacency list
    vector<vector<int>> adj(V);

    for (auto edge: edges) {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);    // u -> v
    }

    vector<int> vis(V, 0);
    stack<int> st;

    // run DFS for all nodes
    for (int i = 0; i < V; i++) {
        if (vis[i] == 0)    dfs(i, adj, vis, st);
        
    }

    // pop from stack to get topo order
    vector<int> ans;

    while (!st.empty()) {
        ans.push_back(st.top());
        st.pop();
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

    vector<int> ans = topoSortDFS(V, edges);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}