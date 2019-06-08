/*
Q-URL: https://leetcode-cn.com/problems/find-the-town-judge
*/

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> judge(N, 0);
        for (auto &t : trust)
        {
            judge[t[0]-1] = -1;
            if (judge[t[1]-1] != -1) ++judge[t[1]-1];
        }
        for (int i = 0; i < N; ++i)
        {
            if (judge[i] == N-1) return i + 1;
        }
        return -1;
    }
};
