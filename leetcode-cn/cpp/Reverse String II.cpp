/*
Q-URL: https://leetcode-cn.com/problems/reverse-string-ii
*/

class Solution {
public:
    void reverse(string &str, int l, int r)
    {
        while (l < r)
        {
            swap(str[l++], str[r--]);
        }
    }
    
    string reverseStr(string s, int k) {
        for (size_t i = 0; i < s.size(); i += 2 * k)
        {
            reverse(s, i, min(i + k - 1, s.size() - 1));
        }
        return s;
    }
};
