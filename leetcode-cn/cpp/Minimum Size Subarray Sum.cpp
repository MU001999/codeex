/*
Q-URL: https://leetcode-cn.com/problems/minimum-size-subarray-sum/
# BEATS 98.63%
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int cnt = INT_MAX;
        for (int _begin = 0, _end = 0, _sum = 0; _end < nums.size(); ++_end)
        {
            _sum += nums[_end];
            if (_sum >= s)
            {
                while (_sum >= s) _sum -= nums[_begin++];
                if (_end - _begin + 1 < cnt) cnt = _end - _begin + 2;
            }
        }
        return cnt == INT_MAX ? 0 : cnt;
    }
};
