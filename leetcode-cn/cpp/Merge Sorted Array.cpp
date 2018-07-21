/*
Q-URL: https://leetcode-cn.com/problems/merge-sorted-array/description/
# ALL BEATS 100%
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        auto nums = new vector<int>();
        int i = 0, j = 0;
        while (i < m && j < n) {
            nums->push_back(nums1[i] < nums2[j] ? nums1[i++] : nums2[j++]);
        }
        while (i < m) nums->push_back(nums1[i++]);
        while (j < n) nums->push_back(nums2[j++]);
        nums1 = *nums;
    }
};

//---------------------------------------------------------------------------

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        while (n--) nums1[m++] = nums2[n];
        sort(nums1.begin(), nums1.end());
    }
};
