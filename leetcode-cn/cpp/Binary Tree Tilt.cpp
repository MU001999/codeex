/*
Q-URL: https://leetcode-cn.com/problems/binary-tree-tilt/submissions/
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
    pair<int, int> helper(TreeNode* root) {
        if (!root) {
            return { 0, 0 };
        }
        auto l = helper(root->left),
             r = helper(root->right);
        return { l.first + r.first + abs(l.second - r.second), l.second + r.second + root->val };
    }

public:
    int findTilt(TreeNode* root) {
        return helper(root).first;
    }
};
