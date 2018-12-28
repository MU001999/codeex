/*
Q-URL: https://leetcode-cn.com/problems/add-binary/
# BEATS 91.42%
*/


class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int c = 0, lena = a.size(), lenb = b.size();
        while (lena-- && lenb--)
        {
            int s = c + a[lena] + b[lenb] - '0' - '0';
            c = s / 2;
            res += to_string(s % 2);
        }
        if (lenb < 0) ++lena;
        while (lena-- > 0)
        {
            int s = c + a[lena] - '0';
            c = s / 2;
            res += to_string(s % 2);
        }
        while (lenb-- > 0)
        {
            int s = c + b[lenb] - '0';
            c = s / 2;
            res += to_string(s % 2);
        }
        if (c) res += '1';
        reverse(res.begin(), res.end());
        return res;
    }
};
