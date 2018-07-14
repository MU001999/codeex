/*
Q-URL: https://leetcode-cn.com/problems/rotate-image/description/
# BEATS 99.93%
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        size_t n = matrix.size();
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
