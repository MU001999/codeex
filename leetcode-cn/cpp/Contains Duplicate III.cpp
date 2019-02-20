/*
Q-URL: https://leetcode-cn.com/problems/contains-duplicate-iii/
*/

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> ss;
        
        long lt = t;
        
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > k) ss.erase(nums[i-k-1]);
            auto it = ss.lower_bound(nums[i] - lt);
            if (it != ss.end() && (*it) - nums[i] <= lt) return true;
            ss.insert(nums[i]);
        }
        
        return false;
    }
};
