/*
Q-URL: https://leetcode-cn.com/problems/two-sum/description/
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;

        unordered_map<int, int> mapping_idx;
        for (int i = 0; i < nums.size(); ++i) {
            if (mapping_idx.count(target - nums[i])) {
                return { mapping_idx[target - nums[i]], i };
            } else {
                mapping_idx[nums[i]] = i;
            }
        }

        return res;
    }
};
