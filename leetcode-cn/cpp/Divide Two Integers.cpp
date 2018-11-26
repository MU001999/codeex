/*
Q-URL: https://leetcode-cn.com/problems/divide-two-integers/
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        else if (dividend == divisor) return 1;
        if (dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        auto negative = (dividend ^ divisor) >> 31, res = 0, count = 0;
        
        if (dividend < 0) dividend = ~dividend + 1;
        if (divisor < 0) divisor = ~divisor + 1;
        
        for (int i = 31; i > 0; --i) if (!((1 << i) & divisor)) ++count; else break;
        
        for (int i = count; i >= 0; --i)
        {
            res <<= 1;
            if (dividend && gt(dividend, (divisor << i)))
            {
                dividend -= (divisor << i);
                ++res;
            }
        }
        
        return negative ? -res : res;
    }
    
    bool gt(int a, int b)
    {
        for (int i = 31; i >= 0; --i)
        {
            auto pica = (1 << i) & a, picb = (1 << i) & b;
            if (!pica && picb) return false;
            else if (pica && !picb) return true;
        }
        return true;
    }
};
