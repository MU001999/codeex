/*
Q-URL: https://leetcode-cn.com/problems/valid-sudoku/description/
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (size_t i = 0; i < 9; ++i) for (size_t j = 0; j < 9; ++j) {
            if (board[i][j] == '.') continue;
            for (size_t k = j + 1; k < 9; ++k) if (board[i][j] == board[i][k]) return false;
            for (size_t k = i + 1; k < 9; ++k) if (board[i][j] == board[k][j]) return false;
            for (size_t k = (i%3)*3+(j%3)+1; k < 9; ++k) if (board[i][j] == board[i+k/3-i%3][j+k%3-j%3]) return false;
        }
        return true;
    }
};
