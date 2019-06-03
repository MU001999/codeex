/*
Q-URL: https://leetcode-cn.com/problems/height-checker
*/

class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> temp = heights;
        sort(temp.begin(), temp.end());
        int result = 0;
        for (size_t i = 0; i < heights.size(); ++i)
        {
            result += (heights[i] != temp[i]);
        }
        return result;
    }
};
