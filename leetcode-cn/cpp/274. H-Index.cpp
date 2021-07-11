/*
Q-URL: https://leetcode-cn.com/problems/h-index/description/
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), std::greater<int>());
        for (int i = 0; i < citations.size(); ++i) {
            if (citations[i] <= i) {
                return i;
            }
        }
        return citations.size();
    }
};
