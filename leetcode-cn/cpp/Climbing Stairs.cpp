/* 
Q-URL: https://leetcode-cn.com/problems/climbing-stairs/description/
# BEATS 100%
*/

class Solution {
public:
    int climbStairs(int n, int a = 1, int b = 2, int c = 3) {
        if (--n < 2) return n + 1;
        while (--n) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};
