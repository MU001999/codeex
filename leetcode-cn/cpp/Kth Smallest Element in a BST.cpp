/*
Q-URL: https://leetcode-cn.com/submissions/detail/9694117/
# BEATS 98.27%
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode *root, vector<int>& nums)
    {
        if (root) 
        {
            helper(root->left, nums);
            nums.push_back(root->val); 
            helper(root->right, nums);
        }
    }
    
    int kthSmallest(TreeNode* root, int k) {
        vector<int> nums;
        helper(root, nums);
        return nums[k - 1];
    }
};
