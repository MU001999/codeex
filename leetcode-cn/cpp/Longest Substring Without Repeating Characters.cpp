/*
Q-URL: https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/description/
# BEATS 93.66%
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() < 2) return s.size();
        int mp[128], res = 0, now = 0, i = 0, l = -1;
        memset(mp, -1, sizeof(mp));
        for (auto &c: s) {
            if (mp[c] <= l) ++now;
            else {
                now = i - mp[c];
                for (auto &m: mp) if (m < mp[c]) m = -1;
            }
            mp[c] = i++;
            res = max(res, now); 
        }
        return res;
    }
};
