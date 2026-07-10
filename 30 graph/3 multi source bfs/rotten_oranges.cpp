#include <bits/stdc++.h>
using namespace std;

// GFG---> Rotting Oranges
// leetcode Q->994      Rotten Oranges


// -------- SOLVE --------
int orangesRotting(vector<vector<int>>& grid){

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<int,int>> q;
    int fresh = 0;

    // Step 1: push all rotten oranges + count fresh
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(grid[i][j] == 2)         q.push({i,j});   // multi-source BFS
            else if(grid[i][j] == 1)    fresh++;
            
        }
    }

    int time = 0;

    // 4 directions
    int dr[] = {-1, 0, 1, 0};
    int dc[] = {0, 1, 0, -1};

    // Step 2: BFS (level = time)
    while(!q.empty() && fresh > 0){

        int size = q.size();
        time++;   // one level = one minute

        while(size>0){

            auto front = q.front();
            
            int r = front.first;
            int c = front.second;
            q.pop();

            for(int k = 0; k < 4; k++){
                int nr = r + dr[k];
                int nc = c + dc[k];

                // valid + fresh orange
                if(nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1){
                    
                    grid[nr][nc] = 2;   // rot it
                    fresh--;
                    q.push({nr, nc});
                }
            }
            
            size--;
        
        }

    }

    // if fresh still left → impossible
    if(fresh > 0) return -1;

    return time;
}


// -------- MAIN --------
int main(){

    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };

    int ans = orangesRotting(grid);

    cout << "Minimum Time: " << ans << endl;

    return 0;
}