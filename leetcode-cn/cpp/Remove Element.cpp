/*
Q-URL: https://leetcode-cn.com/problems/remove-element/
# BEATS 100%
*/


class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int val_pos = 0, lav_pos = nums.size() - 1;
        while (val_pos <= lav_pos) 
        {
            while (val_pos < lav_pos && nums[val_pos] != val) ++val_pos;
            while (lav_pos > val_pos && nums[lav_pos] == val) --lav_pos;
            if (val_pos >= lav_pos) return lav_pos + (nums[val_pos] != val);
            swap(nums[val_pos++], nums[lav_pos--]);
        }
        return lav_pos + 1;
    }
};
