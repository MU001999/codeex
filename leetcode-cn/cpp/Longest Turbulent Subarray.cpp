/*
Q-URL: https://leetcode-cn.com/problems/longest-turbulent-subarray/submissions/
*/

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if (A.size() == 1) {
            return 1;
        }

        enum {
            EQ, UP, DOWN
        } state = (A[0] < A[1]) ? UP : ((A[0] > A[1]) ? DOWN : EQ);

        int result, now;
        result = now = state == EQ ? 1 : 2;

        for (size_t i = 2; i < A.size(); ++i) {
            if ((state == UP and A[i] < A[i-1]) or (state == DOWN and A[i] > A[i-1])) {
                state = state == UP ? DOWN : UP;
                ++now;
            } else {
                state = (A[i-1] < A[i]) ? UP : ((A[i-1] > A[i]) ? DOWN : EQ);
                now = state == EQ ? 1 : 2;
            }
            result = max(result, now);
        }

        return result;
    }
};
