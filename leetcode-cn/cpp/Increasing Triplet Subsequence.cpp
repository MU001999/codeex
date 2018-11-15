/*
Q-URL: https://leetcode-cn.com/problems/increasing-triplet-subsequence/
# BEATS 99.49%
*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        vector<int> record = {nums[0]};
        vector<int>::size_type i = 0;
        for (auto &num: nums)
        {
            if (record.size() == 1)
            {
                if (num < record[0]) record[0] = num;
                else if (num > record[0]) record.push_back(num);
            }
            else 
            {
                if (num < record[0]) record[0] = num;
                else if (num > record[1]) return true;
                else if (num > record[0]) record[1] = num;
            }
        }
        return false;
    }
};
