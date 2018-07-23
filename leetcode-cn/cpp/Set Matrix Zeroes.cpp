/*
Q-URL: https://leetcode-cn.com/problems/set-matrix-zeroes/description/
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int h = matrix.size(), w = matrix[0].size();
        for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) if (matrix[i][j] == 0) {
            for (int y = 0; y < w; ++y) if (matrix[i][y] != 0) matrix[i][y] = -INT_MAX;
            for (int x = 0; x < h; ++x) if (matrix[x][j] != 0) matrix[x][j] = -INT_MAX;
        }
        for (int i = 0; i < h; ++i) for (int j = 0; j < w; ++j) if (matrix[i][j] == -INT_MAX) matrix[i][j] = 0;
    }
};
