#include <bits/stdc++.h>
using namespace std;

// GFG---> DFS of graph         just return a vector storing dfs


// -------- DFS HELPER --------
void dfsHelper(int node, vector<vector<int>> &adj, vector<int> &res, vector<int> &vis) {

    vis[node] = 1;
    res.push_back(node);

    for (int neigh : adj[node]) {

        if (vis[neigh] == 0)    dfsHelper(neigh, adj, res, vis);
        
    }
}


// -------- MAIN DFS --------
vector<int> dfs(vector<vector<int>> &adj) {

    int n = adj.size();

    vector<int> vis(n, 0);
    vector<int> res;

    dfsHelper(0, adj, res, vis);

    return res;
}



int main() {

    int n = 5;

    vector<vector<int>> adj(n);

    // Graph
    adj = {{2, 3, 1}, {0}, {0, 4}, {0}, {2}};

    vector<int> ans = dfs(adj);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}