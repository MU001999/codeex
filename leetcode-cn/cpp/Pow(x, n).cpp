/*
Q-URL: https://leetcode-cn.com/problems/powx-n/
# BEATS 100%
*/

class Solution {
public:
    double myPow(const double x, const int n) {
        if (n == 0) return 1.0;
        else if (n < 0) return 1.0 / x / myPow(x, -n-1);
        else if (n == 1) return x;
        else if (n == 2) return x * x;
        if (n & 1)
        {
            auto tmp = myPow(x, n / 2);
            return tmp * tmp * x;
        }
        else 
        {
            x = myPow(x, n / 2);
            return x * x;
        }
    }
};

/*
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1.0;
        else if (n < 0) return 1.0 / x / myPow(x, -n-1);
        else if (n == 1) return x;
        else if (n == 2) return x * x;
        return myPow(myPow(x, n / 2), 2) * ((n & 1) ? x : 1);
    }
};
*/
