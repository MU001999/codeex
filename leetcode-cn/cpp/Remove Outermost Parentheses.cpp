/*
Q-URL: https://leetcode-cn.com/problems/remove-outermost-parentheses
*/

class Solution {
public:
    string removeOuterParentheses(string S) {
        string res;
        int left = 0;
        for (auto c : S)
        {
            if (c == '(')
            {
                if (++left == 1) continue;
                res += c;
            }
            else
            {
                if (--left == 0) continue;
                res += c;
            }
        }
        return res;
    }
};
