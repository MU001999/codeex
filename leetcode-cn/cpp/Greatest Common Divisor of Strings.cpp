/*
Q-URL: https://leetcode-cn.com/problems/greatest-common-divisor-of-strings
*/

class Solution {
private:
    int gcd(int a, int b)
    {
        return b ? gcd(b, a % b) : a;
    }
    
public:
    string gcdOfStrings(string str1, string str2) {
        auto len = gcd(str1.size(), str2.size());
        auto res = str1.substr(0, len);
        for (int i = 0; i < str1.size();)
        {
            for (int j = 0; j < len; ++j, ++i)
            {
                if (str1[i] != res[j]) return "";
            }
        }
        for (int i = 0; i < str2.size();)
        {
            for (int j = 0; j < len; ++j, ++i)
            {
                if (str2[i] != res[j]) return "";
            }
        }
        return res;
    }
};
