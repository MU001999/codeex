/*
Q-URL: https://leetcode-cn.com/problems/occurrences-after-bigram
# BEATS 100%
*/

class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> res;
        
        text.push_back(' ');
        string word;
        
        enum State
        {
            None,
            First,
            Second
        };
        State state = None;
        
        for (auto c : text)
        {
            if (c == ' ')
            {
                if (state == Second)
                {
                    res.push_back(word);
                    state = None;
                }
                if (state == First) state = word == second ? Second : None;
                if (word == first) state = First;
                word.clear();
            }
            else word.push_back(c);
        }
        
        return res;
    }
};
