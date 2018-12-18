/*
Q-URL: https://leetcode-cn.com/problems/minimum-moves-to-equal-array-elements
# BEATS 94.71%
*/


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size(), m = *min_element(nums.begin(), nums.end()), res = 0;
        for (auto num: nums) res += num - m;
        return res;
    }
};
