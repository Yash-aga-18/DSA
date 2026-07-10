#include <bits/stdc++.h>
using namespace std;

// leetcode Q->802   Find Eventual Safe States


// -------- EVENTUAL SAFE NODES --------
vector<int> eventualSafeNodes(vector<vector<int>>& graph) {

    int V = graph.size();

    vector<vector<int>> rev(V);   // reverse graph
    vector<int> outdegree(V, 0);

    // build reverse graph + outdegree
    for (int i = 0; i < V; i++) {

        outdegree[i] = graph[i].size();

        for (auto neigh : graph[i]) {
            rev[neigh].push_back(i);   // reverse edge
        }
    }

    // queue for nodes with outdegree 0
    queue<int> q;

    for (int i = 0; i < V; i++) {
        if (outdegree[i] == 0)      q.push(i);
    }

    // BFS
    vector<int> safe;

    while (!q.empty()) {

        int node = q.front();
        q.pop();

        safe.push_back(node);

        for (auto prev : rev[node]) {

            outdegree[prev]--;
            if (outdegree[prev] == 0)   q.push(prev);
        }
    }

    // sort result (required)
    sort(safe.begin(), safe.end());

    return safe;
}


// -------- DRIVER --------
int main() {

    vector<vector<int>> graph = {
        {1, 2},
        {2, 3},
        {5},
        {0},
        {5},
        {},
        {}
    };

    vector<int> ans = eventualSafeNodes(graph);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}