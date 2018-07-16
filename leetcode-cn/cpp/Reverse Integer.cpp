/*
Q-URL: https://leetcode-cn.com/problems/reverse-integer/description/
*/

class Solution {
public:
    int reverse(int x) {
        string str;
        int sign = (x >= 0) ? 1 : -1;
        str = to_string(sign * x);
        std::reverse(str.begin(), str.end());
        if (str.size() >= 10 && ((sign && str >= "2147483647") || str >= "2147483648")) return 0;
        return sign * atoi(str.c_str());
    }
};

//----------------------------------------------------------------------------------------------
// this isn't a resolution about string.

class Solution {
public:
    int reverse(int x) {
        int result = 0, temp;
        while (x) {
            temp = result * 10 + x % 10;
            if (temp / 10 != result) return 0;
            x /= 10;
            result = temp;
        }
        return result;
    }
};
