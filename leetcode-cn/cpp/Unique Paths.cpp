/*
Q-URL: https://leetcode-cn.com/problems/unique-paths/
# BEATS 100%
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> res(m, 1);
        while (--n) for (auto i = 1; i < m; ++i) res[i] += res[i-1];
        return res[m-1];
    }
};
