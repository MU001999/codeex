/*
Q-URL: https://leetcode-cn.com/problems/group-the-people-given-the-group-size-they-belong-to/submissions/
*/

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        map<int, vector<int>> groups;
        for (size_t i = 0; i < groupSizes.size(); ++i) {
            auto size = groupSizes[i];
            groups[size].push_back(i);
            if (groups[size].size() == size) {
                result.push_back(groups[size]);
                groups[size].clear();
            }
        }
        return result;
    }
};
