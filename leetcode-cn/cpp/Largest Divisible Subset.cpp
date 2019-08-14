/*
Q-URL: https://leetcode-cn.com/problems/largest-divisible-subset
*/

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> dp(nums.size(), 1),
                    idx(nums.size(), -1);
        int start = 0, max = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0 && dp[i] < dp[j] + 1)
                {
                    dp[i] = dp[j] + 1;
                    idx[i] = j;
                }
            }
            if (dp[i] > max)
            {
                start = i;
                max = dp[i];
            }
        }
        
        vector<int> res;
        for (int i = 0; i < max; ++i)
        {
            res.push_back(nums[start]);
            start = idx[start];
        }
        return res;
    }
};
