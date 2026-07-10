#include <bits/stdc++.h>
using namespace std;

// leetcode Q->210   Course Schedule II


// -------- TOPO SORT --------
vector<int> topoSort(int V, vector<vector<int>>& edges) {

    // build adjacency list + indegree
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    
    for (auto &edge : edges) {
        int v = edge[0];
        int u = edge[1];

        adj[u].push_back(v);
        indegree[v]++;
    }

    // push nodes with indegree 0
    queue<int> q;
    for (int i = 0; i < V; i++) {
        if (indegree[i] == 0)   q.push(i);
    }

    // BFS (Kahn’s Algorithm)
    vector<int> ans;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        ans.push_back(node);

        // adjacency traversal
        for (auto neigh : adj[node]) {

            indegree[neigh]--;
            if (indegree[neigh] == 0)   q.push(neigh);
        }
    }

    return ans;
}



vector<int> findOrder(int V, vector<vector<int>>& edges) {


    vector<int> ans = topoSort(V, edges);

    if (ans.size() != V)    return {};

    return ans;
    
}


int main() {

    int V = 4;

    // {course, prerequisite}
    vector<vector<int>> edges = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    vector<int> ans = findOrder(V, edges);

    if (ans.empty()) {
        cout << "No valid order (cycle exists)";
    } else {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }

    return 0;
}