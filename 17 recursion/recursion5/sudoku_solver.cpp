#include <bits/stdc++.h>
using namespace std;

// leetcode Q->37   Sudoku Solver
// solve the given sudoku


// check if placing ch at (r,c) is valid
bool isSafe(vector<vector<char>>& board, int r, int c, char ch) {

    for (int i = 0; i < 9; i++) {

        // check row
        if (board[r][i] == ch) return false;

        // check column
        if (board[i][c] == ch) return false;

        // check 3x3 box
        int row = 3*(r/3) + i/3;
        int col = 3*(c/3) + i%3;

        if (board[row][col] == ch) return false;
    }

    return true;   // safe to place
}


// backtracking solver
bool solve(vector<vector<char>>& board) {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            // find empty cell
            if (board[i][j] == '.') {

                // try all numbers 1 to 9
                for (char ch = '1'; ch <= '9'; ch++) {

                    if (isSafe(board, i, j, ch)) {

                        board[i][j] = ch;     // choose

                        if (solve(board)) return true;   // explore

                        board[i][j] = '.';   // undo (backtrack)
                    }
                }

                return false;  // no valid number works here
            }


        }
    }

    return true;   // all cells filled → solved
}


void solveSudoku(vector<vector<char>>& board) {

    solve(board);   
}



int main() {

    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    solveSudoku(board);

    // print solved board
    for (auto& row : board) {
        for (auto& c : row) cout << c << " ";
        cout << "\n";
    }

    return 0;
}