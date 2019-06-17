/*
Q-URL: https://leetcode-cn.com/problems/maximize-sum-of-array-after-k-negations
*/

class Solution {
public:
    int largestSumAfterKNegations(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        int res = accumulate(A.begin(), A.end(), 0);
        for (int i = 0; i < A.size(); ++i)
        {
            if (K <= 0) break;
            else if (A[i] >= 0)
            {
                if (K & 1)
                {
                    if (i == 0)
                    {
                        res -= A[i] * 2;
                    }
                    else
                    {
                        res -= min(-A[i-1] * 2, A[i] * 2);
                    }
                }
                break;
            }
            --K;
            res -= A[i] * 2;
        }
        return res;
    }
};
