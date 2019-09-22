/*
Q-URL: https://leetcode-cn.com/problems/image-smoother
# BEATS 100%
*/

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {
        int m = M.size(), n = M.front().size();
        vector<vector<int>> result(m, vector<int>(n));
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int _n = 0, sum = 0;
                for (int _i = max(0, i-1); _i <= min(m-1, i+1); ++_i)
                {
                    for (int _j = max(0, j-1); _j <= min(n-1, j+1); ++_j)
                    {
                        sum += M[_i][_j];
                        ++_n;
                    }
                }
                result[i][j] = sum / _n;
            }
        }
        return result;
    }
};
