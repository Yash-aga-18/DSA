#include <bits/stdc++.h>
using namespace std;

// leetcode Q->36  Valid Sudoku
// check if the given  sudoku state is valid or not


bool isValidSudoku(vector<vector<char>>& board) {

    // sets to track seen numbers
    vector<set<char>> row(9), col(9), box(9);

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.') continue;   // skip empty cells

            char val = board[i][j];

            int b = (i/3)*3 + (j/3);   // convert (i,j) → box index (0 to 8)

            // if already exists → invalid sudoku
            if (row[i].count(val) || col[j].count(val) || box[b].count(val))       return false;

            // mark this value as seen
            row[i].insert(val);
            col[j].insert(val);
            box[b].insert(val);
        }
    }

    return true;   // no conflicts found
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

    cout << (isValidSudoku(board) ? "Valid\n" : "Invalid\n");

    return 0;
}