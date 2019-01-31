/*
Q-URL: https://leetcode-cn.com/problems/reverse-words-in-a-string/
*/

class Solution {
public:
    void reverseWords(string &s) {
        s += ' ';
        string tmp, res;
        for (auto c : s)
        {
            if (c != ' ') tmp += c;
            else if (!tmp.empty())
            {
                res = res.empty() ? tmp : (tmp + " " + res);
                tmp = "";
            }
        }
        s = res;
    }
};

