/*
Q-URL: https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array
# BEATS 100%
*/

class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        set<int> pre;
        for (auto num: A)
        {
            if (pre.count(num)) return num;
            else pre.insert(num);
        }
        return -1;
    }
};
