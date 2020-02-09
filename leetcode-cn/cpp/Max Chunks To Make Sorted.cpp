/*
Q-URL: https://leetcode-cn.com/problems/max-chunks-to-make-sorted/solution/
*/

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int left = 0, result = 0;
        for (int i = 0; i < arr.size(); ++i) {
            left = max(left, arr[i]);
            if (left == i) {
                ++result;
            }
        }
        return result;
    }
};
