/*
Q-URL: https://leetcode-cn.com/problems/string-to-integer-atoi/description/
# BEATS 95.96%
*/

class Solution {
public:
    int myAtoi(string str) {
        int result = 0, sign = 1, temp, i = -1;
        while (str[++i] == ' ');
        if (str[i] == '-') sign = -1;
        else if (str[i] != '+' && !isdigit(str[i--])) return 0;
        while (++i < str.size()) {
            if (!isdigit(str[i])) break;
            temp = result * 10 + str[i] - '0';
            if (temp / 10 != result) return sign == 1 ? INT_MAX : INT_MIN;
            result = temp;
        }
        return sign * result;
    }
};

//----------------------------------------------------------------------------------

class Solution {
public:
    int myAtoi(string str) {
        int temp = 0;
        stringstream stream(str);
        stream>>temp;
        return temp;
    }
};
