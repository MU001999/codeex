/*
Q-URL: https://leetcode-cn.com/problems/base-7
# BEATS 100%
*/

class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0)
        {
            return "0";
        }
        string res;
        bool presign = false;
        if (num < 0)
        {
            presign = true;
            num *= -1;
        }
        while (num)
        {
            res += to_string(num % 7);
            num /= 7;
        }
        reverse(res.begin(), res.end());
        return (presign ? "-" : "") + res;
    }
};
