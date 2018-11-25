/*
Q-URL: https://leetcode-cn.com/problems/factorial-trailing-zeroes/
# BEATS 100%
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        while (n) res += (n /= 5);
        return res;
    }
};
