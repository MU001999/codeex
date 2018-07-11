/*
Q-URL: https://leetcode-cn.com/problems/plus-one/description/
# BEATS 100%
*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits, int carrying = 1) {
        for (int i = digits.size() - 1; i >= 0; --i) carrying = ((digits[i] += carrying) != 10) ? 0 : (digits[i] = 0) == 0;
        if (carrying) digits.insert(digits.begin(), 1);
        return digits;
    }
};
