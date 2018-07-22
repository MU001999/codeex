/*
Q-URL: https://leetcode-cn.com/problems/power-of-three/description/
# BEATS 100%
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
        return (n < 1) ? false : 3486784401L % static_cast<long>(n) == 0;
    }
};
