/*
Q-URL: https://leetcode-cn.com/problems/fibonacci-number
*/

class Solution {
public:
    int fib(int N) {
        if (N < 2) return N;
        int n0 = 0, n1 = 1, n;
        for (int i = 1; i < N; ++i)
        {
            n = n0 + n1;
            n0 = n1;
            n1 = n;
        }
        return n;
    }
};
