/*
Q-URL: https://leetcode-cn.com/problems/two-sum-ii-input-array-is-sorted/
# BEATS 100%
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1, s;
        while (l < r)
        {
            s = numbers[l] + numbers[r];
            if (s == target) return {l+1, r+1};
            else if (s < target) ++l;
            else --r;
        }
        return {};
    }
};
