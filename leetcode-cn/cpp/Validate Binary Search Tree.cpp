/*
Q-URL: https://leetcode-cn.com/problems/validate-binary-search-tree/
# BEATS 100%
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
    bool isValidBST(TreeNode* root, long mn = LONG_MIN, long mx = LONG_MAX) {
        if (!root) return true;
        if (root->val >= mx || root->val <= mn) return false;
        return isValidBST(root->left, mn, root->val) && isValidBST(root->right, root->val, mx);
    }
};
