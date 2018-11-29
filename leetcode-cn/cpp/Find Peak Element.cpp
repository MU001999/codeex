/*
Q-URL: https://leetcode-cn.com/problems/find-peak-element/
# BEATS 99.53%
*/

// O(logN)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        if (nums[0] > nums[1]) return 0;
        if (nums[nums.size() - 1] > nums[nums.size() - 2]) return nums.size() - 1;
        
        int l = 0, r = nums.size() - 1;
        while (l < r)
        {
            auto mid = (l + r) / 2;
            
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) return mid;
            else if (nums[mid] > nums[mid - 1]) l = mid;
            else r = mid;
        }
        return l;
    }
};

// O(N)
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int res = 0;
        while (res + 1 < nums.size())
        {
            if (nums[res] > nums[res + 1]) return res;
            while (++res < nums.size() && nums[res] < nums[res - 1]);
        }
        return res;
    }
};
