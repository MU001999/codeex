/*
Q-URL: https://leetcode-cn.com/problems/minimum-distance-between-bst-nodes
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
private:
    int lastVal_ = INT_MIN, res_ = INT_MAX;
    void helper(TreeNode* root) {
        if (!root) {
            return;
        }
        helper(root->left);
        if (lastVal_ > INT_MIN) {
            res_ = min(res_, root->val - lastVal_);
        }
        lastVal_ = root->val;
        helper(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        helper(root);
        return res_;
    }
};
