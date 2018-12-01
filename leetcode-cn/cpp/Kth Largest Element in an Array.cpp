/*
Q-URL: https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
# BEATS 98.18%
*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        nth_element(nums.begin(), nums.end() - k, nums.end());
        return *(nums.end() - k);
    }
};
