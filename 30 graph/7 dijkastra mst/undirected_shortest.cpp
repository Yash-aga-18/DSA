#include <bits/stdc++.h>
using namespace std;

// GFG-->Shortest Path in Undirected Graph


// -------- SHORTEST PATH --------
vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {

    // build adjacency list
    vector<vector<int>> adj(V);

    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];

        adj[u].push_back(v);
        adj[v].push_back(u);   // undirected
    }

    // distance array
    vector<int> dist(V, -1);

    queue<int> q;
    q.push(src);
    dist[src] = 0;

    // BFS
    while (!q.empty()) {

        int node = q.front();
        q.pop();

        for (auto neigh : adj[node]) {

            if (dist[neigh] == -1) {
                dist[neigh] = dist[node] + 1;
                q.push(neigh);
            }
        }
    }

    return dist;
}



int main() {

    int V = 6;

    vector<vector<int>> edges = {
        {0,1}, {0,2}, {1,3}, {2,4}, {3,5}
    };

    int src = 0;

    vector<int> ans = shortestPath(V, edges, src);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}