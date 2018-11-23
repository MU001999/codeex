/*
Q-URL: https://leetcode-cn.com/problems/generate-parentheses/
# BEATS 100%
*/

class Solution {
public:
    void helper(vector<string> &res, int n, int m, string s)
    {
        if (n)
        {
            helper(res, n - 1, m, s + "(");
            if (m > n) helper(res, n, m - 1, s + ")");
        }
        else res.push_back(s + string(m, ')'));
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helper(res, n, n, "");
        return res;
    }
};
