/*
Q-URL: https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty()) return false;
        int m = matrix.size() - 1, n = 0;
        while (m >= 0 && n < matrix.back().size())
        {
            if (matrix[m][n] == target) return true;
            else if (matrix[m][n] < target) ++n;
            else --m;
        }
        return false;
    }
};
