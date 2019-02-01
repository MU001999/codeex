/*
Q-URL: https://leetcode-cn.com/problems/reverse-vowels-of-a-string/
# BEATS 98.30%
*/

class Solution {
private:
    bool inaeiou(char c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }
    
public:
    string reverseVowels(string s) {
        int l = -1, r = s.size();
        while (l < r)
        {
            while (!inaeiou(s[++l]));
            while (!inaeiou(s[--r]));
            if (l < r) swap(s[l], s[r]);
        }
        return s;
    }
};
