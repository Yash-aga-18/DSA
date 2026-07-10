#include <bits/stdc++.h>
using namespace std;

// GFG--> Flodd Fill algorithm
// leetcode Q->733  Flodd Fill Algorithm


// -------- DFS --------
void dfs(int i, int j, vector<vector<int>>& image, int newColor, int oldColor){
    
    int n = image.size();
    int m = image[0].size();
    
    image[i][j] = newColor;   // color the current cell
    
    // 4 directions
    int dr[] = {0,  0, -1, 1};
    int dc[] = {-1, 1,  0, 0};
    
    for(int k = 0; k < 4; k++){
        int ni = i + dr[k];
        int nj = j + dc[k];
        
        // valid cell + same original color
        if(ni >= 0 && ni < n && nj >= 0 && nj < m && image[ni][nj] == oldColor){
            
            dfs(ni, nj, image, newColor, oldColor);
        }
    }
}


// -------- SOLVE --------
vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color){
    
    int oldColor = image[sr][sc];
    
    if(oldColor == color)       return image;   // important edge case --> if alreday return it
    

    dfs(sr, sc, image, color, oldColor);

    return image;
}


// -------- MAIN --------
int main(){

    vector<vector<int>> image = {
        {1,1,1},
        {1,1,0},
        {1,0,1}
    };
    cout << "originally Filled Image:\n";
    for(auto &row : image){
        for(auto x : row){
            cout << x << " ";
        }
        cout << endl;
    }

    int sr = 1, sc = 1, color = 2;

    vector<vector<int>> ans = floodFill(image, sr, sc, color);

    cout << "Flood Filled Image:\n";
    for(auto &row : ans){
        for(auto x : row){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}