/*
Q-URL: https://leetcode-cn.com/problems/cousins-in-binary-tree/
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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<TreeNode*> nodes = {root};
        
        while (!nodes.empty())
        {
            decltype(nodes) tmp;
            
            bool xe = false, ye = false;
            
            for (auto node: nodes)
            {
                bool txe = false, tye = false;
                if (node->val == x || node->val == y) return false;
                if (node->left)
                {
                    tmp.push_back(node->left);
                    txe = node->left->val == x;
                    tye = node->left->val == y;
                }
                if (node->right)
                {
                    tmp.push_back(node->right);
                    txe += node->right->val == x;
                    tye += node->right->val == y;
                }
                if (txe && tye) return false;
                xe = xe || txe; ye = ye || tye;
            }
            
            if (xe && ye) return true;
            else if (xe || ye) return false;
            
            nodes = tmp;
        }
        
        return false;
    }
};
