/*
Q-URL: https://leetcode-cn.com/problems/pascals-triangle/description/
# BEATS 100%
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows, int l = 0) {
        if (!numRows) return {};
        if (numRows == 1) return {{1}};
        vector<vector<int>> res = {{1}, {1, 1}};
        while (++l < numRows-1)
        {
            vector<int> line = {1};
            for (int i = 0; i < l; ++i) line.push_back(res[l][i] + res[l][i+1]);
            line.push_back(1);
            res.emplace_back(line);
        }
        return res;
    }
};
