/*
Q-URL: https://leetcode-cn.com/problems/word-search/
# BEATS 90.69%
*/

class Solution {
public:
    bool helper(vector<vector<char>> &board, int x, int y, string &word, int wid, vector<vector<char>> &flags) 
    {
        if (wid == word.size()) return true;
        else if (x < 0 || x >= board.size() || y < 0 || y >= board.back().size() || flags[x][y] == 0 || board[x][y] != word[wid]) return false;
        else 
        {
            flags[x][y] = 0;
            auto res = helper(board, x-1, y, word, wid+1, flags) || helper(board, x, y-1, word, wid+1, flags) || helper(board, x+1, y, word, wid+1, flags) || helper(board, x, y+1, word, wid+1, flags);
            flags[x][y] = 1;
            return res;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        auto flags = board;
        for (int x = 0; x < board.size(); ++x)
        {
            for (int y = 0; y < board.back().size(); ++y)
            {
                if (board[x][y] == word[0] && helper(board, x, y, word, 0, flags)) return true;
            }
        }
        return false;
    }
};
