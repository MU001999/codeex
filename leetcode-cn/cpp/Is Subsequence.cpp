/*
Q-URL: https://leetcode-cn.com/problems/is-subsequence
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (auto c : t) {
            if (i < s.size() and c == s[i]) {
                ++i;
            }
        }
        return i == s.size();
    }
};
