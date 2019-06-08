/*
Q-URL: https://leetcode-cn.com/problems/sum-of-even-numbers-after-queries
*/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int now = 0;
        for (auto n : A) if ((n & 1) == 0) now += n;
        for (auto &query : queries)
        {
            auto tmp = A[query[1]] + query[0];
            res.push_back(now += ((tmp & 1) ? ((query[0] & 1) ? -A[query[1]] : 0) : ((query[0] & 1) ? tmp : query[0])));
            A[query[1]] = tmp;
        }
        return res;
    }
};
