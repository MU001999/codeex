/*
Q-URL: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-array/description/
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) return 0;
        int ind = 0;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i-1]) nums[++ind] = nums[i];
            else continue;
        }
        return ind + 1;
    }
};
