/*
Q-URL: https://leetcode-cn.com/problems/number-of-islands/
# BEATS 96.86%
*/

class Solution {
public:
    int dfs(vector<vector<char>> &grid, int i, int j, int h, int w)
    {
        grid[i][j] = '0';
        if (i > 0 && grid[i-1][j] == '1') dfs(grid, i-1, j, h, w);
        if (j > 0 && grid[i][j-1] == '1') dfs(grid, i, j-1, h, w);
        if (i + 1 < h && grid[i+1][j] == '1') dfs(grid, i+1, j, h, w);
        if (j + 1 < w && grid[i][j+1] == '1') dfs(grid, i, j+1, h, w);
        return 1;
    }
    
    int numIslands(vector<vector<char>> &grid) {
        if (grid.empty()) return 0;
        int res = 0, h = grid.size(), w = grid[0].size();
        for (auto i = 0; i < h; ++i) for (auto j = 0; j < w; ++j) if (grid[i][j] == '1') res += dfs(grid, i, j, h, w);
        return res;
    }
};
