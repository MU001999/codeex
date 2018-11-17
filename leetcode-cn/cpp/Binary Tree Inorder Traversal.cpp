/*
Q-URL: https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        
        while (root)
        {
            s.push(root);
            root = root->left;
        }
        
        while (s.size())
        {
            root = s.top(); s.pop();
            res.push_back(root->val);
            root = root->right;
            while (root)
            {
                s.push(root);
                root = root->left;
            }
        }
        return res;
    }
};
