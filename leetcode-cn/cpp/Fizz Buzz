/*
Q-URL: https://leetcode-cn.com/problems/fizz-buzz/description/
# BEATS 100%
*/

class Solution {
public:
    vector<string> fizzBuzz(int n, int i = 0) {
        vector<string> res;
        while (++i <= n) {
            if (i % 15 == 0) res.push_back("FizzBuzz");
            else if (i % 3 == 0) res.push_back("Fizz");
            else if (i % 5 == 0) res.push_back("Buzz");
            else res.push_back(to_string(i));
        }
        return res;
    }
};
