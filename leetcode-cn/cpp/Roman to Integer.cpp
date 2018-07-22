/*
Q-URL: https://leetcode-cn.com/problems/roman-to-integer/description/
*/

class Solution {
public:
    int romanToInt(string s, int res = 0) {
        unordered_map<char, int> m{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        for (int i = 0; i < s.size(); ++i) {
            int val = m[s[i]];
            if (m[s[i+1]] <= m[s[i]] || i == s.size() - 1) res += val;
            else res -= val;
        }
        return res;
    }
};
