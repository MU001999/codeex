/*
Q-URL: https://leetcode-cn.com/problems/3sum/description/
# BEATS 89.10%
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int i = -1) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        while (++i+2 < nums.size()) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    res.push_back({nums[i], nums[l++], nums[r--]});
                    while (nums[l] == nums[l-1]) ++l;
                    while (nums[r] == nums[r+1]) --r;
                }
                else if (nums[l] + nums[r] < target) ++l;
                else --r;
            }
        }
        return res;
    }
};

// Update

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums, int i = -1) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        while (++i+2 < nums.size()) {
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int target = -nums[i];
            int l = i + 1, r = nums.size() - 1;
            while (l < r) {
                if (nums[l] + nums[r] == target) {
                    res.push_back({nums[i], nums[l++], nums[r--]});
                    while (l < nums.size() && nums[l] == nums[l-1]) ++l;
                    while (r >= 0&& nums[r] == nums[r+1]) --r;
                }
                else if (nums[l] + nums[r] < target) ++l;
                else --r;
            }
        }
        return res;
    }
};
