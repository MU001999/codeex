/*
Q-URL: https://leetcode-cn.com/problems/path-sum/
# BEATS 97.91%
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
    bool hasPathSum(TreeNode* root, int sum) {
        return root ? ((sum -= root->val) == 0 && !root->left && !root->right) || hasPathSum(root->left, sum) || hasPathSum(root->right, sum) : false;
    }
};
