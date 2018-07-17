/*
Q-URL: https://leetcode-cn.com/problems/valid-palindrome/description/
# BEATS 100%
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int l = -1, r = s.size();
        transform(s.begin(),s.end(),s.begin(),::tolower);
        while (l < r) {
            while (!isalnum(s[++l]));
            while (!isalnum(s[--r]));
            if (l < r && s[l] != s[r]) return false;
        }
        return true;
    }
};
