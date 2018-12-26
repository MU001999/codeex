/*
Q-URL: https://leetcode-cn.com/problems/01-matrix/
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        auto m = matrix.size(), n = matrix.back().size();
        vector<vector<int>> count(m, vector<int>(n, -1));
        queue<pair<int, int>> nodes;
        for (size_t x = 0; x < m; ++x)
        {
            for (size_t y = 0; y < n; ++y)
            {
                if (matrix[x][y] == 0)
                {
                    nodes.push({x, y});
                    count[x][y] = 0;
                }
            }
        }
        
        while (!nodes.empty())
        {
            decltype(nodes) tmp;
            while (!nodes.empty())
            {
                auto now = nodes.front(); nodes.pop();
                if (now.first > 0 && count[now.first - 1][now.second] == -1)
                {
                    count[now.first - 1][now.second] = count[now.first][now.second] + 1;
                    tmp.push({now.first - 1, now.second});
                }
                if (now.first < m - 1 && count[now.first + 1][now.second] == -1)
                {
                    count[now.first + 1][now.second] = count[now.first][now.second] + 1;
                    tmp.push({now.first + 1, now.second});
                }
                if (now.second > 0 && count[now.first][now.second - 1] == -1)
                {
                    count[now.first][now.second - 1] = count[now.first][now.second] + 1;
                    tmp.push({now.first, now.second - 1});
                }
                if (now.second < n - 1 && count[now.first][now.second + 1] == -1)
                {
                    count[now.first][now.second + 1] = count[now.first][now.second] + 1;
                    tmp.push({now.first, now.second + 1});
                }
            }
            nodes = tmp;
        }
        
        return count;
    }
};
