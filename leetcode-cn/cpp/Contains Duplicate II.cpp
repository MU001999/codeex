/*
Q-URL: https://leetcode-cn.com/problems/contains-duplicate-ii/
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> mps;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (mps.count(nums[i]) && i - mps[nums[i]] <= k) return true;
            mps[nums[i]] = i;
        }
        return false;
    }
};
