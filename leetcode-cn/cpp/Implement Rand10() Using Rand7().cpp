/*
Q-URL: https://leetcode-cn.com/problems/implement-rand10-using-rand7/description/
*/

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10(int d = 0, int d1 = 0, int d2 = 0) {
        do {
            d1 = rand7();
            d2 = (rand7() - 1) * 7;
            d = d1 + d2;
        } while (d >= 11);
        return d % 10 + 1;
    }
};
