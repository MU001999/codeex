/*
Q-URL: https://leetcode-cn.com/problems/rotting-oranges/
# BEATS 100%
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<pair<int, int>> q;
        set<pair<int, int>> vis;
        
        int go[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid.back().size(); ++j)
            {
                if (grid[i][j] == 0) vis.insert({i, j});
                else if (grid[i][j] == 2)
                {
                    vis.insert({i, j});
                    q.push_back({i, j});
                }
            }
        }
        
        int res = 0, m = grid.size(), n = grid.back().size();
        if (vis.size() == m * n) return 0;
        
        res = 0;
        while (true)
        {
            decltype(q) tmp;
            for (auto node: q)
            {
                for (int i = 0; i < 4; ++i)
                {
                    auto x = node.first + go[i][0], y = node.second + go[i][1];
                    if (x < 0 || y < 0 || x >= m || y >= n || vis.count({x, y})) continue;
                    vis.insert({x, y});
                    tmp.push_back({x, y});
                }
            }
            if (tmp.empty()) break;
            q = tmp;
            ++res;
        }
        
        return vis.size() == m * n ? res : -1;
    }
};
