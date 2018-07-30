/*
Q-URL: https://leetcode-cn.com/problems/binary-search/description/
*/

class Solution {
public:
    
    int find(vector<int>& nums, int target, int left, int right) {
        if (left > right) return -1;
        int mid = (left + right) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) return find(nums, target, mid + 1, right);
        else return find(nums, target, left, mid - 1);
    }
    
    int search(vector<int>& nums, int target) {
        return find(nums, target, 0, nums.size()-1);
    }
};

//------------------------------------------------------------------------------

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int low = 0, high = static_cast<int>(nums.size()) - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (target == nums[mid]) return mid;
            else if (target < nums[mid]) high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};
