/*
Q-URL: https://leetcode-cn.com/problems/reordered-power-of-2/description/
*/

class Solution {
public:
    bool reorderedPowerOf2(int N) {
        auto sum = [](int N, int t = 0){ for (; N; N /= 10) t += pow(10, N % 10); return t; };
        for (int i = 0, t = sum(N); i < 32; ++i) if (sum(1<<i) == t) return true;
        return false;
    }
};
