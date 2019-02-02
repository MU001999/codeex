/*
Q-URL: https://leetcode-cn.com/problems/intersection-of-two-arrays/
# BEATS 100%
*/

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        
        set<int> meet;
        for (auto num : nums1) if (!meet.count(num)) meet.insert(num);
        for (auto num : nums2) if (meet.count(num)) 
        {
            meet.erase(num);
            res.push_back(num);
        }
        
        return res;
    }
};
