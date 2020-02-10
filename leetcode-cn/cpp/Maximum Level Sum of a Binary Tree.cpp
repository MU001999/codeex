/*
Q-URL: https://leetcode-cn.com/problems/maximum-level-sum-of-a-binary-tree/submissions/
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
    void helper(TreeNode* root, int level, map<int, int> &count) {
        if (!root) {
            return;
        }
        count[level] += root->val;
        helper(root->left, level + 1, count);
        helper(root->right, level + 1, count);
    }

public:
    int maxLevelSum(TreeNode* root) {
        map<int, int> count;
        helper(root, 1, count);
        int result = 0, sum = INT_MIN;
        for (auto item : count) {
            if (item.second > sum) {
                result = item.first;
                sum = item.second;
            }
        }
        return result;
    }
};
