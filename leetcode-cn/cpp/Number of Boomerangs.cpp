/*
Q-URL: https://leetcode-cn.com/problems/number-of-boomerangs/
*/

class Solution {
private:
    int cal(pair<int, int> &a, pair<int, int> &b)
    {
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    }
    
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int res = 0;
        
        unordered_map<int, int> cnts;
        for (auto &p : points)
        {
            for (auto &q : points) ++cnts[cal(p, q)];
            for (auto &cnt : cnts) res += cnt.second * (cnt.second - 1);
            cnts.clear();
        }
        
        return res;
    }
};
