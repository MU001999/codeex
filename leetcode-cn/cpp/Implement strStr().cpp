/*
Q-URL: https://leetcode-cn.com/problems/implement-strstr/description/
# BEATS 99.30%
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        if(needle.length() > haystack.length()) return -1;
        vector<int> next(needle.size(), -1);
        int k = -1;
        for (int q = 1; q < needle.size(); ++q)
        {
            while (k > -1 && needle[k + 1] != needle[q]) k = next[k];
            if (needle[k + 1] == needle[q]) ++k;
            next[q] = k;
        }
        k = -1;
        for (int i = 0; i < haystack.size(); ++i)
        {
            while (k > -1 && needle[k + 1] != haystack[i]) k = next[k];
            if (needle[k + 1] == haystack[i]) ++k;
            if (k == needle.size() - 1) return i - needle.size() + 1;
        }
        return -1;
    }
};
