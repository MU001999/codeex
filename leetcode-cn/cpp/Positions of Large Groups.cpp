/*
Q-URL: https://leetcode-cn.com/problems/positions-of-large-groups/
# BEATS 100%
*/

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        if (S.size() < 3) return {};
        
        vector<vector<int>> res;
        
        int cnt = 1;
        for (int i = 1; i < S.size(); ++i)
        {
            if (S[i] == S[i-1])
            {
                ++cnt;
            }
            else 
            {
                if (cnt > 2) res.push_back({ i - cnt, i - 1 });
                cnt = 1;
            }
        }
        
        if (cnt > 2) res.push_back({ S.size() - cnt, S.size() - 1 });
        
        return res;
    }
};
