/*
Q-URL: https://leetcode-cn.com/problems/sum-of-two-integers/
# BEATS 100%
*/

class Solution {
public:
    int getSum(int a, int b) {
        auto c = (a & b) << 1;
        a ^= b;
        while (c)
        {
            b = a ^ c;
            c = (a & c) << 1;
            a = b;
        }
        return a;
    }
};
