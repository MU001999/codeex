/*
Q-URL: https://leetcode-cn.com/problems/task-scheduler/
# BEATS 92.54%
*/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (auto &task: tasks) ++cnt[task - 'A'];
        sort(cnt.rbegin(), cnt.rend());
        auto cells = cnt[0], i = 1;
        while (i < 26 && cnt[i] == cells) ++i;
        if (i > n) return tasks.size();
        return max(static_cast<int>(tasks.size()), (cells - 1) * (n + 1) + i);
    }
};
