/*
Q-URL: https://leetcode-cn.com/problems/valid-parentheses/description/
# BEATS 100%
*/

class Solution {
public:
    bool isValid(string s) {
        if (!s.size()) return true;
        stack<char> sk;
        auto r = [](char &chr) {
            return chr == ')' ? '(' : (chr == ']' ? '[' : '{');
        };
        for (char &chr : s) {
            switch(chr) {
                case '(': case '[': case '{':
                    sk.push(chr);
                    break;
                case ')': case ']': case '}':
                    if (sk.empty() || sk.top() != r(chr)) return false;
                    sk.pop();
                    break;
            }
        }
        return sk.empty();
    }
};
