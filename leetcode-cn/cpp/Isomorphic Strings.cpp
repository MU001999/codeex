/*
Q-URL: https://leetcode-cn.com/problems/isomorphic-strings/
# BEATS 99.54%
*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char mps[128] = {0};
        bool chrs[128] = {0};
            
        for (int i = 0; i < s.size(); ++i)
        {
            if (mps[s[i]])
            {
                if (mps[s[i]] != t[i]) return false;
            }
            else if (chrs[t[i]]) return false;
            else
            {
                chrs[t[i]] = true;
                mps[s[i]] = t[i];
            }
        }
        
        return true;
    }
};
