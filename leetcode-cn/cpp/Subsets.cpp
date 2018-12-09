/*
Q-URL: https://leetcode-cn.com/problems/subsets/
# BEATS 100%
*/

class Solution {
public:
    void helper(vector<vector<int>> &res, vector<int> &nums, int i, int c, vector<int> cur) {
        if (c) while (++i <= nums.size() - c) {
            cur.push_back(nums[i]);
            helper(res, nums, i, c-1, cur);
            cur.pop_back();
        } else res.push_back(cur);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}, nums};
        for (auto c = 1; c < nums.size(); ++c) helper(res, nums, -1, c, {});
        return res;
    }
};
