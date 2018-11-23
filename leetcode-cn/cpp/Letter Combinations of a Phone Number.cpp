/*
Q-URL: https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
# BEATS 100%
*/

class Solution 
{
private:
    unordered_map<char, string> cmap = 
    {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
public:
    vector<string> letterCombinations(string digits) 
    {
        vector<string> res;
        for (auto &digit: digits)
        {
            decltype(res) tmp;
            if (res.empty()) for (auto &c: cmap[digit]) res.push_back(string() + c);
            else 
            {
                for (auto &s: res) for (auto &c: cmap[digit]) tmp.push_back(s+c);
                res = tmp;
            }
        }
        return res;
    }
};
