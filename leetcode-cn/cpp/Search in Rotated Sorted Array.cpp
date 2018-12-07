/*
Q-URL: https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
# BEATS 99.81%
*/

class Solution {
public:
    int helper(vector<int> &nums, int l, int r, int target)
    {
        if (l > r) return -1;
        auto mid = (l + r) / 2;
        if (nums[mid] == target) return mid;
        
        if (nums[l] < nums[r]) return (nums[mid] < target) ? helper(nums, mid + 1, r, target) : helper(nums, l, mid - 1, target);
        else if (nums[mid] > nums[r])
        {
            if (nums[mid] > target && nums[l] <= target) return helper(nums, l, mid - 1, target);
            else return helper(nums, mid + 1, r, target);
        }
        else if (nums[mid] > target || nums[l] <= target) return helper(nums, l, mid - 1, target);
        else return helper(nums, mid + 1, r, target);
    }
    
    int search(vector<int>& nums, int target) {
        return helper(nums, 0, nums.size() - 1, target);
    }
};
