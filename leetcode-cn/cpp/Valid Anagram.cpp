/*
Q-URL: https://leetcode-cn.com/problems/valid-anagram/description/
# SOLUTION 1 BEATS 100%
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> count(26, 0);
        for (auto &c : s) ++count[c-'a'];
        for (auto &c : t) --count[c-'a'];
        for (auto &c : count) if (c) return false;
        return true;
    }
};

//------------------------------------------------------------

class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
    }
};
