/*
Q-URL: https://leetcode-cn.com/problems/maximum-element-after-decreasing-and-rearranging/
*/

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
		sort(arr.begin(), arr.end());
    	int ret = 1;
    	for (int i = 1; i < arr.size(); ++i) {
            if (arr[i] == ret) {
                continue;
            } else if (arr[i] == ret + 1) {
                ret = arr[i];
            } else {
                ++ret;
            }
        }
        return ret;
    }
};
