/*
Q-URL: https://leetcode-cn.com/problems/jump-game/
# BEATS 98.80%
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums[0] == 0) return nums.size() == 1;
        auto i = 0, maxright = 0, border = (int)nums.size() - 1;
        while (i <= border)
        {
            for (int j = i; j <= maxright; ++j)
            {
                auto right = j + nums[j];
                if (right >= border) return true;
                else if (right > maxright) maxright = right;
                else if (j == maxright && right == maxright) return false;
            }
        }
        return true;
    }
};
