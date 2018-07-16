/*
Q-URL: https://leetcode-cn.com/problems/first-unique-character-in-a-string/description/
# SOLUTION 1 BEATS 99.32%
*/

class Solution {
public:
    int firstUniqChar(string s, int i = -1, int p = INT_MAX) {
        vector<int> pos(26, -1);
        while (++i < s.size()) pos[s[i]-'a'] = (pos[s[i]-'a'] == -1) ? i : -2;
        for (auto &ind : pos) if (ind >= 0 && ind < p) p = ind;
        return p == INT_MAX ? -1 : p;
    }
};

//----------------------------------------------------------------------------

class Solution {
public:
    int firstUniqChar(string s) {
        int count[26] = {0};
        for (auto &chr : s) ++count[chr-'a'];
        for (int i = 0; i < s.size(); ++i) if (count[s[i]-'a'] == 1) return i;
        return -1;
    }
};
