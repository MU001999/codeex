/*
Q-URL: https://leetcode-cn.com/problems/add-to-array-form-of-integer
# BEATS 98.27%
*/

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        A.back() += K;
        auto it = A.end();
        while (it != A.begin())
        {
            --it;
            if (*it >= 10 && it != A.begin())
            {
                *(it - 1) += *it / 10;
                *it %= 10;
            }
        }
        while (*it >= 10)
        {
            auto t = *it / 10;
            *it %= 10;
            A.insert(it, t);
            it = A.begin();
        }
        return A;
    }
};
