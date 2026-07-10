#include <bits/stdc++.h>
using namespace std;

// GFG----> nearest ones


// -------- SOLVE --------
vector<vector<int>> updateMatrix(vector<vector<int>>& mat){

    int n = mat.size();
    int m = mat[0].size();
    
    queue<pair<int,int>> q;
    vector<vector<int>> dist(n, vector<int>(m, -1));

    // Step 1: push all 1s (multi-source BFS)
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(mat[i][j] == 1){
                q.push({i, j});
                dist[i][j] = 0;   // distance of 1 = 0
            }
        }
    }

    // 4 directions
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    // Step 2: BFS
    while(!q.empty()){
        
        auto front = q.front();

        int r = front.first;
        int c = front.second;
        q.pop();

        for(int k = 0; k < 4; k++){
            int nr = r + dr[k];
            int nc = c + dc[k];

            // valid + not visited
            if(nr >= 0 && nr < n && nc >= 0 && nc < m 
               && dist[nr][nc] == -1){
                
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    return dist;
}


int main(){

    vector<vector<int>> mat = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };

    vector<vector<int>> ans = updateMatrix(mat);

    cout << "Distance Matrix:\n";
    for(auto &row : ans){
        for(auto x : row){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}