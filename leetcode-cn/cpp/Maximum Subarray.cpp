/*
Q-URL: https://leetcode-cn.com/problems/maximum-subarray/description/
# BEATS 97.45%
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums, int now = 0, int res = INT_MIN) {
        for (int &num : nums) {
            now += num;
            res = max(now, res);
            now = max(now, 0);
        }
        return res;
    }
};
