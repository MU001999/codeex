/*
Q-URL: https://leetcode-cn.com/problems/exclusive-time-of-functions
# BEATS 100%
*/

class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> count(n, 0);
        stack<pair<int, int>> call_stack;
        for (auto &log : logs) {
            auto pos1 = log.find(':');
            auto id = stoi(log.substr(0, pos1));
            if (log[pos1 + 1] == 's') {
                auto time = stoi(log.substr(pos1 + 7));
                if (!call_stack.empty()) {
                    count[call_stack.top().first] += time - call_stack.top().second;
                }
                call_stack.push({ id, time });
            } else {
                auto time = stoi(log.substr(pos1 + 5));
                auto cur = call_stack.top(); call_stack.pop();
                count[cur.first] += time - cur.second + 1;
                if (!call_stack.empty()) {
                    call_stack.top().second = time + 1;
                }
            }
        }
        return count;
    }
};
