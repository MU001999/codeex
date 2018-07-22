/*
Q-URL: https://leetcode-cn.com/problems/house-robber/description/
# BEATS 100%
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() < 2) return nums.empty() ? 0 : nums[0];
        vector<int> dp = nums;
        dp[1] = max(dp[0], dp[1]);
        for (size_t i = 2; i < dp.size(); ++i) dp[i] = max(dp[i-1], dp[i-2] + dp[i]);
        return dp[dp.size()-1];
    }
};
