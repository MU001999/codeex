/*
Q-URL: https://leetcode-cn.com/problems/guess-number-higher-or-lower/
# BEATS 100%
*/

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        long l = 0, m = n / 2, r = n;
        while (int res = guess(m))
        {
            if (res == -1) tie(m, r) = make_tuple((l + m - 1) / 2, m - 1);
            else tie(l, m) = make_tuple(m + 1, (m + 1 + r) / 2);
        }
        return m;
    }
};
