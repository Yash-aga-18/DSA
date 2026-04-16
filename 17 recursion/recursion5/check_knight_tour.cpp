#include <bits/stdc++.h>
using namespace std;

// leetcode Q->2596  Check Knight Tour Configuration


bool checkValidGrid(vector<vector<int>>& grid) {

    int n = grid.size();

    // knight moves (8 possible)
    vector<pair<int,int>> moves = {
        {2,1}, {2,-1}, {-2,1}, {-2,-1},
        {1,2}, {1,-2}, {-1,2}, {-1,-2}
    };

    // must start from (0,0)
    if (grid[0][0] != 0)        return false;

    // store position of each number
    vector<pair<int,int>> pos(n*n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            pos[grid[i][j]] = {i, j};   // where each step occurs
        }
    }

    // check every consecutive move
    for (int k = 1; k < n*n; k++) {

        int r1 = pos[k-1].first;
        int c1 = pos[k-1].second;

        int r2 = pos[k].first;
        int c2 = pos[k].second;

        bool valid = false;

        // check if (k-1 → k) is a valid knight move
        for (auto &m : moves) {
            if (r1 + m.first == r2 && c1 + m.second == c2) {
                valid = true;
                break;
            }
        }

        if (!valid) return false;   // invalid move found
    }

    return true;   // all moves valid
}



int main() {

    vector<vector<int>> grid = {
        {0,11,16,5,20},
        {17,4,19,10,15},
        {12,1,8,21,6},
        {3,18,23,14,9},
        {24,13,2,7,22}
    };

    cout << (checkValidGrid(grid) ? "Valid\n" : "Invalid\n");

    return 0;
}