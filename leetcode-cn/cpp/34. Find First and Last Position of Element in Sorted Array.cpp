/*
Q-URL: https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
# BEATS 100%
*/


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1, lidx = -1, ridx = -1;
        while (left <= right) {
            if (left == right) {
                if (nums[left] == target) {
                    lidx = left;
                }
                break;
            }

            auto mid = (left + right) / 2;
            if (nums[mid] == target) {
                if (mid == 0 || nums[mid - 1] < target) {
                    lidx = mid;
                    break;
                } else {
                    right = mid - 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        left = 0, right = nums.size() - 1;
        while (left <= right) {
            if (left == right) {
                if (nums[left] == target) {
                    ridx = left;
                }
                break;
            }

            auto mid = (left + right) / 2;
            if (nums[mid] == target) {
                if (mid == nums.size() - 1 || nums[mid + 1] > target) {
                    ridx = mid;
                    break;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return {lidx, ridx};
    }
};
