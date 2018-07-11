/*
Q-URL: https://leetcode-cn.com/problems/intersection-of-two-arrays-ii/description/
# BEATS 100%
*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2, int i = 0, int j = 0) {
        vector<int> res;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i++] == nums2[j++]) res.push_back(nums1[i-1]);
            else if (nums1[i-1] < nums2[j-1])  --j;
            else --i;
        }
        return res;
    }
};
