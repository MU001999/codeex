/*
Q-URL: https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
# BEATS 98.80%
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> res;
        vector<TreeNode*> layer = {root};
        while (layer.size())
        {
            res.push_back(vector<int>());
            auto tmp = layer;
            layer.clear();
            for (auto &root: tmp)
            {
                if (res.size() & 1) res.back().push_back(root->val);
                else res.back().insert(res.back().begin(), root->val);
                if (root->left) layer.push_back(root->left);
                if (root->right) layer.push_back(root->right);
            }
        }
        return res;
    }
};
