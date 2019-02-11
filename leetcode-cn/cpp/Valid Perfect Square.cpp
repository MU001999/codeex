/*
Q-URL: https://leetcode-cn.com/problems/valid-perfect-square/
# BEATS 100%
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        if (num == 1) return true;
        int l = 0, r = num;
        long long now, m = num / 2;
        while (l <= r)
        {
            now = m * m;
            if (now == num) return true;
            else if (now < num) tie(l, m) = make_tuple(m + 1, (m + 1 + r) / 2);
            else tie(m, r) = make_tuple((l + m - 1) / 2, m - 1);
        }
        return now == num;
    }
};
