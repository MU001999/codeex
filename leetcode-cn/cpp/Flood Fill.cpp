/*
Q-URL: https://leetcode-cn.com/problems/flood-fill/
# BEATS 97.94%
*/

class Solution {
public:
    void dfs(vector<vector<int>> &image, vector<vector<bool>> &visited, int x, int y, int m, int n, int oldc, int newc)
    {
        if (visited[x][y]) return;
        visited[x][y] = true;
        if (image[x][y] != oldc) return;
        image[x][y] = newc;
        if (x > 0) dfs(image, visited, x - 1, y, m, n, oldc, newc);
        if (y > 0) dfs(image, visited, x, y - 1, m, n, oldc, newc);
        if (x < m - 1) dfs(image, visited, x + 1, y, m, n, oldc, newc);
        if (y < n - 1) dfs(image, visited, x, y + 1, m, n, oldc, newc);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image.empty()) return {};
        auto m = image.size(), n = image.back().size(); 
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(image, visited, sr, sc, m, n, image[sr][sc], newColor);
        return image;
    }
};
