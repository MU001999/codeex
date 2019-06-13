/*
Q-URL: https://leetcode-cn.com/problems/goat-latin
# BEATS 100%
*/

class Solution {
private:
    bool isvowel(char c)
    {
        for (auto chr : "aeiouAEIOU") if (c == chr) return true;
        return false;
    }
    
public:
    string toGoatLatin(string S) {
        S.push_back(' ');
        string res, word;
        int i = 0;
        
        for (auto c : S)
        {
            if (c == ' ')
            {
                if (isvowel(word[0]))
                {
                    res += (res.empty() ? "" : " ") + word + "ma"s + string(++i, 'a');
                }
                else
                {
                    res += (res.empty() ? "" : " ") + word.substr(1) + word[0] + "ma"s + string(++i, 'a');
                }
                word.clear();
            }
            else word.push_back(c);
        }
        
        return res;
    }
};
