/*
Q-URL: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
# BEATS 97.41%
*/


class Solution {
public:
    int helper(vector<int>& nums, int target, int l, int r, bool left)
    {
        if (l > r) return -1;
        auto mid = (l + r) / 2;
        if (nums[mid] == target)
        {
            if (left)
            {
                if (mid > 0 && nums[mid-1] == target) return helper(nums, target, l, mid - 1, left);
            }
            else if (mid + 1 < nums.size() && nums[mid + 1] == target) return helper(nums, target, mid + 1, r, left);
            return mid;
        }
        else if (nums[mid] < target) return helper(nums, target, mid + 1, r, left);
        else return helper(nums, target, l, mid - 1, left);
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        return {helper(nums, target, 0, nums.size() - 1, true), helper(nums, target, 0, nums.size() - 1, false)};
    }
};
