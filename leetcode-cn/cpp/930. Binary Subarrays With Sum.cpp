/*
Q-URL: https://leetcode-cn.com/problems/binary-subarrays-with-sum/
*/

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ret = 0;
        int sum = 0;
        unordered_map<int, int> cnt;
        for (const auto &num : nums) {
            ++cnt[sum];
            sum += num;
            ret += cnt[sum - goal];
        }
        return ret;
    }
};
