/*
Q-URL: https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
# BEATS 99.22%
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (auto &token: tokens)
        {
            switch (token[0])
            {
            case '+':
            case '*':
            case '/':
            {
                auto a = s.top(); s.pop();
                auto b = s.top(); s.pop();
                switch (token[0])
                {
                case '+':
                    s.push(b + a); 
                    break;
                case '*':
                    s.push(b * a); 
                    break;
                case '/':
                    s.push(b / a); 
                    break;
                }
            }
                break;
            case '-':
                if (token.size() == 1)
                {
                    auto a = s.top(); s.pop();
                    auto b = s.top(); s.pop();
                    s.push(b - a); 
                    break;
                }
            default: 
                s.push(stoi(token)); 
                break;
            }
        }
        return s.top();
    }
};
