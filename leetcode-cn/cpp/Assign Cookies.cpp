/*
Q-URL: https://leetcode-cn.com/problems/assign-cookies
*/

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int res = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        for (size_t i = 0, j = 0; i < g.size() && j < s.size();)
        {
            if (g[i] <= s[j])
            {
                ++res, ++i, ++j;
            }
            else
            {
                ++j;
            }
        }
        return res;
    }
};
