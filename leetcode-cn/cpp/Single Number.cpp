/*
Q-URL: https://leetcode-cn.com/problems/single-number/description/
*/

class Solution {
public:
    int singleNumber(vector<int>& nums, int res = 0) {
        for (auto &num : nums) res ^= num;
        return res;
    }
};
