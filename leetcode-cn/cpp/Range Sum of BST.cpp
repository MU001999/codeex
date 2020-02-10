/*
Q-URL: https://leetcode-cn.com/problems/range-sum-of-bst/submissions/
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if (!root) {
            return 0;
        }
        if (L <= root->val and root->val <= R) {
            return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R) + root->val;
        }
        return rangeSumBST(root->left, L, R) + rangeSumBST(root->right, L, R);
    }
};
