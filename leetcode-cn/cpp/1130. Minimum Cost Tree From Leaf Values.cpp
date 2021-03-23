/*
Q-URL: https://leetcode-cn.com/problems/minimum-cost-tree-from-leaf-values
# BEATS 100%
*/

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int result = 0;

        stack<int> lefts;
        lefts.push(INT_MAX);

        for (size_t i = 0; i < arr.size(); ++i) {
            while (lefts.top() <= arr[i]) {
                auto val = lefts.top();
                lefts.pop();
                result += min(arr[i], lefts.top()) * val;
            }
            lefts.push(arr[i]);
        }

        while (lefts.size() > 2) {
            auto val = lefts.top();
            lefts.pop();
            result += lefts.top() * val;
        }

        return result;
    }
};
