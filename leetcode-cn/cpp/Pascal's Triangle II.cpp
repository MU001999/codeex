/*
Q-URL: https://leetcode-cn.com/problems/pascals-triangle-ii/
# BEATS 100%
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res{1, 1};
        if (rowIndex == 0) return {1};
        else if (rowIndex == 1) return res;
        for (int len = 1; len < rowIndex; ++len)
        {
            vector<int> tmp{1};
            for (int i = 0; i < len; ++i) tmp.push_back(res[i] + res[i+1]);
            tmp.push_back(1);
            res = tmp;
        }
        return res;
    }
};
