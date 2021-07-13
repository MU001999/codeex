/*
Q-URL: https://leetcode-cn.com/problems/the-skyline-problem/
*/

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<int> boundaries;
        for (const auto &building : buildings) {
            boundaries.push_back(building[0]);
            boundaries.push_back(building[1]);
        }
        sort(boundaries.begin(), boundaries.end());

        auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) -> bool { return a.second < b.second; };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> que(cmp);

        vector<vector<int>> res;
        int idx = 0, n = buildings.size();
        for (const auto &boundary : boundaries) {
            while (idx < n && buildings[idx][0] <= boundary) {
                que.push({buildings[idx][1], buildings[idx][2]});
                ++idx;
            }

            while (!que.empty() && que.top().first <= boundary) {
                que.pop();
            }

            int h = que.empty() ? 0 : que.top().second;
            if (res.empty() || h != res.back()[1]) {
                res.push_back({boundary, h});
            }
        }

        return res;
    }
};
