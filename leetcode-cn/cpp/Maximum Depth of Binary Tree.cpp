/*
Q-URL: https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
# BEATS 100%
*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return root ? (1 + max(maxDepth(root->left), maxDepth(root->right))) : 0;
    }
};
