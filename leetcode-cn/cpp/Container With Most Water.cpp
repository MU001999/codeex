/*
Q-URL: https://leetcode-cn.com/problems/container-with-most-water/
# BEATS 95.18%
*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int res = INT_MIN, l = 0, r = height.size() - 1;
        while (l < r)
        {
            auto cap = (r - l) * min(height[l], height[r]);
            res = max(res, cap);
            if (height[l] < height[r]) ++l;
            else --r;
        }
        return res;
    }
};
