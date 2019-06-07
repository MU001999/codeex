/*
Q-URL: https://leetcode-cn.com/problems/univalued-binary-tree
# BEATS 96.84%
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
    bool isUnivalTree(TreeNode* root, int val = -1) {
        if (!root) return true;
        else if (val == -1) return isUnivalTree(root->left, root->val) && isUnivalTree(root->right, root->val);
        else return root->val == val && isUnivalTree(root->left, root->val) && isUnivalTree(root->right, root->val);
    }
};
