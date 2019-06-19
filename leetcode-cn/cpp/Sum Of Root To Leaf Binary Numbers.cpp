/*
Q-URL: https://leetcode-cn.com/problems/sum-of-root-to-leaf-binary-numbers/submissions/
# BEATS 96.45%
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
    int sumRootToLeaf(TreeNode* root, int res = 0) {
        constexpr int M = 1000000007;
        if (!root) return res % M;
        else if (root->left && root->right) return (sumRootToLeaf(root->left, (root->val + (res << 1)) % M) + sumRootToLeaf(root->right, (root->val + (res << 1)) % M)) % M;
        else if (root->left) return sumRootToLeaf(root->left, (root->val + (res << 1)));
        else return sumRootToLeaf(root->right, (root->val + (res << 1)) % M);
    }
};
