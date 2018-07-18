/*
Q-URL: https://leetcode-cn.com/problems/count-and-say/description/
#BEATS 100%
*/

class Solution {
public:
    string countAndSay(int n, int i = 0) {
        if (n == 0) return "";
        string result("1");
        while (--n) {
            string temp; i = 0;
            while (i < result.size()) {
                char c = result[i];
                int count = 0;
                while (i < result.size() && result[i] == c) {
                    ++i; ++count;
                }
                temp += count + '0';
                temp += c;
            }
            result = temp;
        }
        return result;
    }
};
