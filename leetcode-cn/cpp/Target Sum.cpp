/*
Q-URL: https://leetcode-cn.com/problems/target-sum/
# BEATS 100% BUT NOT BY MESELF
*/


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum < S || (sum + S) % 2 != 0) return 0;
        auto target = (sum + S) >> 1;
        vector<int> mem(target + 1, 0);
        mem[0] = 1;
        for (auto num: nums)
        {
            for (int i = target; i > num - 1; --i)
                mem[i] += mem[i - num];
        }
        return mem[target];
    }
};
