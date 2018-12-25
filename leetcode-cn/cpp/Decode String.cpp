/*
Q-URL: https://leetcode-cn.com/problems/decode-string/
# BEATS 100%
*/

class Solution {
private:
    string helper(string &s, string::iterator &it)
    {
        if (it == s.end()) return "";
        
        string pre1, pre2, res, ens;
        
        while (isalpha(*it)) pre1 += *it++;
        
        if (it == s.end()) return pre1;
        
        while (isdigit(*it)) pre2 += *it++;
        
        if (pre2.empty()) return pre1;
        
        ++it;
        
        while (*it != ']')
        {
            if (isdigit(*it)) ens += helper(s, it);
            else ens += *it++;
        }
        
        ++it;
        
        auto k = stoi(pre2);
        while (k--) res += ens;
        
        return pre1 + res;
    }
    
public:
    string decodeString(string s) {
        string res;
        
        auto it = s.begin();
        while (it != s.end()) res += helper(s, it);
        
        return res;
    }
};
