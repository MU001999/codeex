/*
Q-URL: https://leetcode-cn.com/problems/reverse-words-in-a-string-iii/
# BEATS 96.53%
*/

class Solution {
private:
    
    void _reverse(string &s, int l, int r)
    {
        while (l < r) swap(s[l++], s[r--]);
    }
    
public:
    
    string reverseWords(string s) {
        int begin = 0, end = 0;
        for (; end < s.size(); ++end)
        {
            if (s[end] == ' ')
            {
                _reverse(s, begin, end-1);
                begin  = end + 1;
            }
        }
        _reverse(s, begin, end-1);
        return s;
    }
};

