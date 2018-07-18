/*
Q-URL: https://leetcode-cn.com/problems/longest-common-prefix/description/
# BEATS 99.72%
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs, int i = 0) {
        if (!strs.size()) return "";
        string result = strs[i];
        int len = result.size(), ind;
        while (++i < strs.size()) {
            len = min(len, static_cast<int>(strs[i].size()));
            for (ind = 0; ind < len; ++ind) if (result[ind] != strs[i][ind]) break;
            len = ind;
        }
        return result.substr(0, len);
    }
};
