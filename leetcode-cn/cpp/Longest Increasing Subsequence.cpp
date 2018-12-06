/*
Q-URL: https://leetcode-cn.com/problems/longest-increasing-subsequence/
# BEATS 100%
*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (auto i = 0; i < nums.size(); ++i)
        {
            auto pos = lower_bound(res.begin(), res.end(), nums[i]);
            if (pos == res.end()) res.push_back(nums[i]);
            else *pos = nums[i];
        }
        return res.size();
    }
};
