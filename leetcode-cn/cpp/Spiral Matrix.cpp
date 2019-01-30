/*
Q-URL: https://leetcode-cn.com/problems/spiral-matrix/
# BEATS 100%
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        if (matrix.empty()) return res;
        int m = matrix.size(), n = matrix.back().size();
        int c =  (min(m, n) + 1) / 2, p = m, q = n;
        for (int i = 0; i < c; ++i, p -= 2, q -= 2) {
            for (int col = i; col < i + q; ++col) 
                res.push_back(matrix[i][col]);
            for (int row = i + 1; row < i + p; ++row)
                res.push_back(matrix[row][i + q - 1]);
            if (p == 1 || q == 1) break;
            for (int col = i + q - 2; col >= i; --col)
                res.push_back(matrix[i + p - 1][col]);
            for (int row = i + p - 2; row > i; --row) 
                res.push_back(matrix[row][i]);
        }
        return res;
    }
};
