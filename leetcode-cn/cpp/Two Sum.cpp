/*
Q-URL: https://leetcode-cn.com/problems/two-sum/description/
# BEATS 100%
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> nums2 = nums;
        sort(nums.begin(), nums.end());
        int i = 0, j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                int a = -1, b = nums.size();
                while (nums2[++a] != nums[i]);
                while (nums2[--b] != nums[j]);
                return {b, a};
            }
            else if (nums[i] + nums[j] < target) ++i;
            else --j;
        }
    }
};
