/*
Valid Sudoku
Solved

You are given a a 9 x 9 Sudoku board board. A Sudoku board is valid if the following rules are followed:

    Each row must contain the digits 1-9 without duplicates.
    Each column must contain the digits 1-9 without duplicates.
    Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without duplicates.

Return true if the Sudoku board is valid, otherwise return false

Note: A board does not need to be full or be solvable to be valid.

Example 2:
Input: board = 
[["1","2",".",".","3",".",".",".","."],
 ["4",".",".","5",".",".",".",".","."],
 [".","9","1",".",".",".",".",".","3"],
 ["5",".",".",".","6",".",".",".","4"],
 [".",".",".","8",".","3",".",".","5"],
 ["7",".",".",".","2",".",".",".","6"],
 [".",".",".",".",".",".","2",".","."],
 [".",".",".","4","1","9",".",".","8"],
 [".",".",".",".","8",".",".","7","9"]]

Output: false

Explanation: There are two 1's in the top-left 3x3 sub-box.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkBox(int i, int j) {

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> row[9], col[9], box[3][3];
        for(int i=0; i<9; ++i) {
            for(int j=0; j<9; ++j) {
                if(board[i][j] == '.') continue;
                
                int x = (board[i][j]-'0');
                
                if (row[i].find(x) != row[i].end()) return false;
                row[i].insert(x);

                if(col[j].find(x) != col[j].end()) return false;
                col[j].insert(x);

                if(box[i/3][j/3].find(x) != box[i/3][j/3].end()) return false;
                box[i/3][j/3].insert(x);
            }
        }

        return true;
    }
};
