/*
Q-URL: https://leetcode-cn.com/problems/longest-palindromic-substring/
# BEATS 99.77%
*/

class Solution {
public:
    string longestPalindrome(string _s) {
        string s("#"), res;
        for (auto &c: _s)
        {
            s += c;
            s += '#';
        }
        
        vector<int> RL(s.size(), 0);
        int max_right = 0, pos = 0, rpos = 0;
        
        for (string::size_type i = 0; i < s.size(); ++i)
        {
            RL[i] = (i < max_right) ? min((int)(RL[2 * pos - i]), (int)(max_right - i)) : 1;
            while (i >= RL[i] && i + RL[i] < s.size() && s[i - RL[i]] == s[i + RL[i]]) ++RL[i];
            if (i + RL[i] - 1 > max_right) max_right = (pos = i) + RL[i] - 1;
            if (RL[i] > RL[rpos]) rpos = i;
        }
        
        for (string::size_type i = rpos - RL[rpos] + 2; i < rpos + RL[rpos]; i += 2) res += s[i];
        
        return res;
    }
};
