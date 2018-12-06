/*
Q-URL: https://leetcode-cn.com/problems/top-k-frequent-elements/
# BEATS 98.70%
*/

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<int> res;
        for (auto &num: nums) ++count[num];
        for (auto c: count) res.push_back(c.first);
        sort(res.rbegin(), res.rend(), [&](const int &a, const int &b) { return count[a] < count[b]; });
        res.erase(res.begin() + k, res.end());
        return res;
    }
};
