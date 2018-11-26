/*
Q-URL: https://leetcode-cn.com/problems/sqrtx/
# BEATS 99.01%
*/

class Solution {
public:
    int mySqrt(int x) {
        long i = 0, j = x / 2 + 1;
        while (i <= j)
        {
            auto mid = (i + j) / 2;
            auto sq = mid * mid;
            if (sq == x) return mid;
            else if (sq < x) i = mid + 1;
            else j = mid - 1;
        }
        return j;
    }
};
