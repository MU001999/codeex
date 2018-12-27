/*
Q-URL: https://leetcode-cn.com/problems/largest-number-at-least-twice-of-others/
# BEATS 100%
*/


class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int pos_max = 0, pos_sec_max = 0;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] > nums[pos_max])
            {
                pos_sec_max = pos_max;
                pos_max = i;
            }
            else if (nums[i] > nums[pos_sec_max] || pos_max == pos_sec_max) pos_sec_max = i;
        }
        if (nums[pos_max] >= nums[pos_sec_max] * 2) return pos_max;
        return -1;
    }
};
