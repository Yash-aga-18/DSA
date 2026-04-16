#include <bits/stdc++.h>
using namespace std;

// GFG---> ARt in a mze
// it is kinda similar to maze path
// but additional--> it can go up or left also


void backtrack(int r, int c, vector<vector<int>>& maze, int n,
               vector<vector<int>>& vis, string& path, vector<string>& ans) {

    // reached destination
    if (r == n-1 && c == n-1) {
        ans.push_back(path);
        return;
    }

    // mark current cell visited
    vis[r][c] = 1;

    // DOWN
    if (r+1 < n && maze[r+1][c] == 1 && !vis[r+1][c]) {
        path.push_back('D');
        backtrack(r+1, c, maze, n, vis, path, ans);
        path.pop_back();
    }

    // LEFT
    if (c-1 >= 0 && maze[r][c-1] == 1 && !vis[r][c-1]) {
        path.push_back('L');
        backtrack(r, c-1, maze, n, vis, path, ans);
        path.pop_back();
    }

    // RIGHT
    if (c+1 < n && maze[r][c+1] == 1 && !vis[r][c+1]) {
        path.push_back('R');
        backtrack(r, c+1, maze, n, vis, path, ans);
        path.pop_back();
    }

    // UP
    if (r-1 >= 0 && maze[r-1][c] == 1 && !vis[r-1][c]) {
        path.push_back('U');
        backtrack(r-1, c, maze, n, vis, path, ans);
        path.pop_back();
    }

    // unmark (backtrack)
    vis[r][c] = 0;
}


vector<string> ratInMaze(vector<vector<int>>& maze, int n) {

    vector<string> ans;

    if (maze[0][0] == 0)    return ans;

    vector<vector<int>> vis(n, vector<int>(n, 0));
    string path = "";

    backtrack(0, 0, maze, n, vis, path, ans);

    return ans;
}


int main() {

    int n = 5;

    vector<vector<int>> maze = {
        {1, 1, 0, 1, 1},
        {0, 1, 1, 1, 0},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 1, },
        {1, 1, 1, 1, 1}
    };

    vector<string> ans = ratInMaze(maze, n);

    cout<<"possible ways : "<<ans.size()<<endl;

    for (auto& s : ans) {
        cout << s << "\n";
    }

    return 0;

}