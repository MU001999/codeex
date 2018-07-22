/*
Q-URL: https://leetcode-cn.com/problems/number-of-1-bits/description/
# BEATS 100%
*/

class Solution {
public:
    int hammingWeight(uint32_t n, int res = 0) {
        while (n) {
            ++res;
            n &= n-1;
        }
        return res;
    }
};
