/*
Q-URL: https://leetcode-cn.com/problems/complement-of-base-10-integer
# BEATS 100%
*/

class Solution {
public:
    int bitwiseComplement(int N) {
        if (N == 0) return 1;
        int n = 1;
        while (n <= N) n = n << 1;
        return n - N - 1;
    }
};
