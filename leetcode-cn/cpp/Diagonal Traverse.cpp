/*
Q-URL: https://leetcode-cn.com/problems/diagonal-traverse/
# BEATS 98.45%
*/

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        vector<int> res;
        int i = 0, j = 0;
        while (true)
        {
            while (i >= 0 && j < matrix.back().size()) res.push_back(matrix[i--][j++]);
            ++i;
            if (j == matrix.back().size())
            {
                if (i == matrix.size() - 1) break;
                ++i; --j;
            }
            while (i < matrix.size() && j >= 0) res.push_back(matrix[i++][j--]);
            ++j;
            if (i == matrix.size())
            {
                if (j == matrix.back().size() - 1) break;
                ++j; --i;
            }
        }
        return res;
    }
};
