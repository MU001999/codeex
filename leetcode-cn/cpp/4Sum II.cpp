/*
Q-URL: https://leetcode-cn.com/problems/4sum-ii/
*/

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int res = 0;
        unordered_map<int, int> mps;
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < A.size(); ++j)
                ++mps[A[i] + B[j]];
        for (int i = 0; i < A.size(); ++i)
            for (int j = 0; j < A.size(); ++j)
                res += mps[-C[i] - D[j]];
        return res;
    }
};
