/*
Q-URL: https://leetcode-cn.com/problems/move-zeroes/description/
# BEATS 99.61%
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums, int ind = 0, int i = 0) {
        while (i < nums.size()) if (nums[i++]) nums[ind++] = nums[i-1];
        while (ind < nums.size()) nums[ind++] = 0;
    }
};
