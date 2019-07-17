/*
Q-URL: https://leetcode-cn.com/problems/keyboard-row
*/

class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> res;
        set<char> first
        {
            'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p'
        };
        set<char> second
        {
            'a', 's', 'd', 'f', 'g', 'h', 'i', 'j', 'k', 'l'
        };
        set<char> third
        {
            'z', 'x', 'c', 'v', 'b', 'n', 'm'
        };
        
        for (auto &word : words)
        {
            bool fit = true;
            for (int i = 0, flag; i < word.size(); ++i)
            {
                auto c = ::tolower(word[i]);
                if (i == 0)
                {
                    if (first.count(c))
                    {
                        flag = 1;
                    }
                    else if (second.count(c))
                    {
                        flag = 2;
                    }
                    else
                    {
                        flag = 3;
                    }
                }
                else
                {
                    if (flag == 1)
                    {
                        if (!first.count(c))
                        {
                            fit = false;
                            break;
                        }
                    }
                    else if (flag == 2)
                    {
                        if (!second.count(c))
                        {
                            fit = false;
                            break;
                        }
                    }
                    else
                    {
                        if (!third.count(c))
                        {
                            fit = false;
                            break;
                        }
                    }
                }
            }
            if (fit)
            {
                res.push_back(word);
            }
        }
        
        return res;
    }
};
