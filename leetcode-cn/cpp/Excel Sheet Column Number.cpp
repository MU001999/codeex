/*
Q-URL: https://leetcode-cn.com/problems/excel-sheet-column-number/
# BEATS 100%
*/

class Solution {
public:
    int titleToNumber(string s) {
        auto i = 0, res = s[0] - 64;
        while (++i < s.size()) res = res * 26 + s[i] - 64;
        return res;
    }
};
