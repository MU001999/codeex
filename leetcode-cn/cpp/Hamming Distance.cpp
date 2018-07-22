/*
Q-URL: https://leetcode-cn.com/problems/hamming-distance/description/
# BEATS 100%
*/

class Solution {
public:
    int hammingDistance(int x, int y, int res = 0) {
        x ^= y;
        while (x) {
            ++res;
            x &= x-1;
        }
        return res;
    }
};
