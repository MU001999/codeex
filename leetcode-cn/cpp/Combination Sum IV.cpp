/*
Q-URL: https://leetcode-cn.com/problems/combination-sum-iv/
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<uint64_t> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < dp.size(); ++i) {
            for (int j = 0; j < nums.size() and nums[j] <= i; ++j) {
                dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};
