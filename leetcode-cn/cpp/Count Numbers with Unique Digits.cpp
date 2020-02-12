/*
Q-URL: https://leetcode-cn.com/problems/count-numbers-with-unique-digits/
# BEATS 100%
*/

class Solution {
private:
    constexpr int A(int n, int m) {
        int result = 1;
        for (m = n - m + 1; m <= n; ++m) {
            result *= m;
        }
        return result;
    }

public:
    constexpr int countNumbersWithUniqueDigits(int n) {
        int result = 1;
        for (n = min(n, 9); n > 0; --n) {
            result += 9 * A(9, n - 1);
        }
        return result;
    }
};
