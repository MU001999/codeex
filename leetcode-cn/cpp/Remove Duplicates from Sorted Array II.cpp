/*
Q-URL: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array-ii/
# BEATS 98.65%
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l = 0, r = 0, len = 0, cnt = 0;
        while (r < nums.size())
        {
            while (r < nums.size() && nums[r] == nums[l]) ++r;
            ++cnt;
            if (r - l > 1) ++cnt;
            while (cnt--) nums[len++] = nums[l];
            l = r;
            cnt = 0;
        }
        return len;
    }
};

