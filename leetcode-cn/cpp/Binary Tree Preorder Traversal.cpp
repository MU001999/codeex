/*
Q-URL: https://leetcode-cn.com/problems/binary-tree-preorder-traversal/
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        
        stack<TreeNode*> nodes;
        nodes.push(root);
        
        while (!nodes.empty())
        {
            auto now = nodes.top(); nodes.pop();
            
            res.push_back(now->val);
            if (now->right) nodes.push(now->right);
            if (now->left) nodes.push(now->left);
        }
        
        return res;
    }
};
