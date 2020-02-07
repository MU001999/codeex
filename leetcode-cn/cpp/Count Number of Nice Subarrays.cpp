/*
Q-URL: https://leetcode-cn.com/problems/count-number-of-nice-subarrays/submissions/
*/

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int left = 0;
        while (left < nums.size() and nums[left] % 2 == 0) {
            ++left;
        }
        int right = left, numOfOdd = 0;
        while (right < nums.size()) {
            if (nums[right] % 2 == 1) {
                ++numOfOdd;
            }
            if (numOfOdd == k) {
                break;
            }
            ++right;
        }
        if (numOfOdd != k) {
            return 0;
        }

        int result = 0, l = -1;
        while (right < nums.size()) {
            int r = right + 1;
            while (r < nums.size() and nums[r] % 2 == 0) {
                ++r;
            }
            result += (r - right) * (left - l);
            l = left++;
            while (left < nums.size() and nums[left] % 2 == 0) {
                ++left;
            }
            right = r;
        }
        return result;
    }
};
