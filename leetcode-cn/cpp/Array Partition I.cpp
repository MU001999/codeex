/*
Q-URL: https://leetcode-cn.com/problems/array-partition-i/
# BEATS 92.08%
*/

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); i += 2)
        {
            res += min(nums[i], nums[i-1]);
        }
        return res;
    }
};
