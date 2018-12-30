/*
Q-URL: https://leetcode-cn.com/problems/max-consecutive-ones/
# BEATS 94.91%
*/

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, res = 0;
        for (auto num: nums)
        {
            cnt = num ? cnt + 1 : 0;
            res = max(cnt, res);
        }
        return res;
    }
};
