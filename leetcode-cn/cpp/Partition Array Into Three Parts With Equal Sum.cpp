/*
Q-URL: https://leetcode-cn.com/problems/partition-array-into-three-parts-with-equal-sum
*/

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int sum = accumulate(A.begin(), A.end(), 0);
        if (sum % 3) return false;
        int average = sum / 3, i = 0, now = 0, sp = 0;
        while (i < A.size())
        {
            now += A[i++];
            if (now == average)
            {
                now = 0;
                ++sp;
            }
        }
        return sp == 3;
    }
};
