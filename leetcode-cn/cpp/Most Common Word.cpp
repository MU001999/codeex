/*
Q-URL: https://leetcode-cn.com/problems/most-common-word
# BEATS 99.53%
*/

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        paragraph.push_back(' ');

        string res, tmp;
        int mcnt = 0;
        unordered_map<string, int> cnts;
        unordered_set<string> b(banned.begin(), banned.end());
        for (auto c : paragraph)
        {
            if (!isalpha(c))
            {
                if (!tmp.empty() && !b.count(tmp))
                {
                    ++cnts[tmp];
                    if (mcnt < cnts[tmp])
                    {
                        mcnt = cnts[tmp];
                        res = tmp;
                    }
                }
                tmp.clear();
            }
            else tmp += tolower(c);
        }
        return res;
    }
};
