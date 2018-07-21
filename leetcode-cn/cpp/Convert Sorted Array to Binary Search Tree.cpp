/*
Q-URL: https://leetcode-cn.com/problems/convert-sorted-array-to-binary-search-tree/description/
# BEATS 100%
*/

class Solution {
public:
    TreeNode* helper(vector<int>& nums, int left, int right) {
        if (left > right) return NULL;
        int mid = (left + right) / 2;
        auto node = new TreeNode(nums[mid]);
        node->left = helper(nums, left, mid-1);
        node->right = helper(nums, mid+1, right);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, nums.size()-1);
    }
};
