/*
Q-URL: https://leetcode-cn.com/problems/minimum-index-sum-of-two-lists/
# BEATS 94.31%
*/

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int min_cnt = INT_MAX;
        vector<string> res;
        unordered_map<string ,int> mps;
        for (int i = 0; i < list1.size(); ++i) mps[list1[i]] = i;
        for (int i = 0; i < list2.size(); ++i) if (mps.count(list2[i]))
        {
            auto cnt = mps[list2[i]] + i;
            if (cnt < min_cnt)
            {
                min_cnt = cnt;
                res = {list2[i]};
            }
            else if (cnt == min_cnt) res.push_back(list2[i]);
        }
        return res;
    }
};
