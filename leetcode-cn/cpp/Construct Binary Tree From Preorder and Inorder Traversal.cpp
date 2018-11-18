/*
Q-URL: https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
# BEATS 86.25%
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
class Solution 
{
private:
    TreeNode* helper(vector<int>& preorder, vector<int>&iorder, int pb, int pe, int ib, int ie)
    {
        if (pb > pe) return NULL;
        auto res = new TreeNode(preorder[pb]);
        for (auto i = ib; i <= ie; ++i) 
        {
            if (iorder[i] == preorder[pb])
            {
                res->left = helper(preorder, iorder, pb + 1, pb + i - ib, ib, i - 1);
                res->right = helper(preorder, iorder, pb + 1 + i - ib, pe, i + 1, ie);
                break;
            }
        }
        return res;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
