/*
Q-URL: https://leetcode-cn.com/problems/find-duplicate-subtrees/
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
    string helper(vector<TreeNode*> &res, unordered_map<string, int> &mps, TreeNode *root)
    {
        if (!root) return "#";
        auto str = to_string(root->val) + ","s + helper(res, mps, root->left) + ","s + helper(res, mps, root->right);
        if (mps[str] == 1) res.push_back(root);
        ++mps[str];
        return str;
    }
    
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string, int> mps;
        helper(res, mps, root);
        return res;
    }
};
