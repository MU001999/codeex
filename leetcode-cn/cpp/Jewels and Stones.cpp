/*
Q-URL: https://leetcode-cn.com/problems/jewels-and-stones/
# BEATS 99.56%
*/

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        bool meet[128] = {0};
        for (auto c : J) meet[c] = true;
        int res = 0;
        for (auto c : S) res += meet[c];
        return res;
    }
};
