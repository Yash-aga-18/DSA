#include <bits/stdc++.h>
using namespace std;

bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathVis) {

    vis[node] = 1;
    pathVis[node] = 1;

    for (auto neigh : adj[node]) {

        if (!vis[neigh]) {
            if (dfs(neigh, adj, vis, pathVis)) return true;
        }

        else if (pathVis[neigh])    return true;
        
    }

    pathVis[node] = 0;
    return false;
}



bool isCycle(int V, vector<vector<int>> &adj) {

    vector<int> vis(V, 0);
    vector<int> pathVis(V, 0);

    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, vis, pathVis)) return true;
        }
    }
    return false;
}


int main() {

    int V = 3;
    vector<vector<int>> adj = {
        {1}, {2}, {0}
    };

    cout << isCycle(V, adj);

    return 0;
}