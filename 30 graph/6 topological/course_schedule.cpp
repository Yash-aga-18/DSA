#include <bits/stdc++.h>
using namespace std;

// leetcode Q->207      Course Schedule 1



// -------- TOPO SORT --------
vector<int> topoSort(int V, vector<vector<int>>& edges) {

    // build adjacency list + indegree
    vector<vector<int>> adj(V);
    vector<int> indegree(V, 0);

    // use auto for edges
    for (auto &edge : edges) {
        int u = edge[0];
        int v = edge[1];

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


// -------- CHECK IF POSSIBLE --------
bool canFinish(int V, vector<vector<int>>& edges) {

    vector<int> ans = topoSort(V, edges);

    return ans.size() == V;   // no cycle if all nodes processed
}



int main() {

    int V = 4;

    vector<vector<int>> edges = {
        {1, 0},
        {2, 1},
        {3, 2}
    };

    if (canFinish(V, edges)) {
        cout << "Possible (No Cycle)";
    } else {
        cout << "Not Possible (Cycle Exists)";
    }

    return 0;
}