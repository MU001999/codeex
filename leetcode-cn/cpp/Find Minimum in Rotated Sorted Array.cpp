/*
Q-URL: https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
# BEATS 98.88%
*/

class Solution {
private:
    int helper(vector<int> &nums, int left, int right)
    {
        if (left >= right) return nums[left];
        auto mid = (left + right) / 2;
        if (nums[mid-1] > nums[mid]) return nums[mid];
        else if (nums[mid] > nums[right]) return helper(nums, mid + 1, right);
        else return helper(nums, left, mid - 1);
    }
    
public:
    int findMin(vector<int>& nums) {
        return helper(nums, 0, nums.size() - 1);
    }
};
