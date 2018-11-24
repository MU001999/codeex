/*
Q-URL: https://leetcode-cn.com/problems/happy-number/
# BEATS 100%
*/

class Solution {
public:
    bool isHappy(int n) {
        if (n == 1) return true;
        else if (n == 4) return false;
        auto next = 0;
        while (n)
        {
            next += (n % 10) * (n % 10);
            n /= 10;
        }
        return isHappy(next);
    }
};
