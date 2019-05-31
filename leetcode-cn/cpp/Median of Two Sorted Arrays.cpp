/*
Q-URL: https://leetcode-cn.com/problems/median-of-two-sorted-arrays
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) swap(nums1, nums2);
        auto m = nums1.size(), n = nums2.size();
        size_t imin = 0, imax = m, half_len = (m + n + 1) / 2;
        while (imin <= imax)
        {
            auto i = (imin + imax) / 2;
            auto j = half_len - i;
            if (i < m and nums1[i] < nums2[j - 1])
            {
                imin = i + 1;
            }
            else if (i > 0 and nums1[i - 1] > nums2[j])
            {
                imax = i - 1;
            }
            else
            {
                double max_left, min_right;
                if (i == 0) max_left = nums2[j - 1];
                else if (j == 0) max_left = nums1[i - 1];
                else max_left = max(nums1[i - 1], nums2[j - 1]);
                
                if ((m + n) & 1) return max_left;
                
                if (i == m) min_right = nums2[j];
                else if (j == n) min_right = nums1[i];
                else min_right = min(nums1[i], nums2[j]);
                
                return (max_left + min_right) / 2.0;
            }
        }
        return 0.0;
    }
};
