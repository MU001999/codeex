/*
Q-URL: https://leetcode-cn.com/problems/number-of-lines-to-write-string
# BEATS 100%
*/

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        if (S.empty()) return { 0, 0 };
        int now = 0, lines = 1;
        for (size_t i = 0; i < S.size();)
        {
            if (now + widths[S[i] - 'a'] > 100)
            {
                ++lines;
                now = 0;
            }
            else now += widths[S[i++] - 'a'];
        }
        return { lines, now };
    }
};
