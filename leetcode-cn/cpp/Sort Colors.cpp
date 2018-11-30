/*
Q-URL: https://leetcode-cn.com/problems/sort-colors/
*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int begin = 0, current = 0, end = nums.size() - 1;
        while (current <= end)
        {
            if (nums[current] == 0)
            {
                nums[current++] = nums[begin];
                nums[begin++] = 0;
            }
            else if (nums[current] == 2)
            {
                nums[current] = nums[end];
                nums[end--] = 2;
            }
            else ++current;
        }
    }
};
