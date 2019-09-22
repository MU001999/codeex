/*
Q-URL: https://leetcode-cn.com/problems/preimage-size-of-factorial-zeroes-function
# BEATS 100%
*/

class Solution {
private:
    long long zeros(long long N)
    {
        int res = 0;
        while (N / 5)
        {
            res += (N /= 5);
        }
        return res;
    }
public:
    int preimageSizeFZF(int K) {
        long long left = 0, right = 5 * static_cast<long long>(K);
        while (true)
        {
            if (left > right)
            {
                return 0;
            }
            auto mid = (left + right) / 2;
            auto tmp = zeros(mid);
            if (tmp == K)
            {
                return 5;
            }
            else if (tmp < K)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
};
