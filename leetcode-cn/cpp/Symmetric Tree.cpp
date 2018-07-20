/*
Q-URL: https://leetcode-cn.com/problems/symmetric-tree/description/
# ALL BEATS 100%
*/

class Solution {
public:
    bool isSymmetric(TreeNode* root, int n = 0) {
        if (!root) return true;
        queue<TreeNode*> q;
        vector<long> line;
        q.push(root);
        while ((n = q.size())) {
            line.clear();
            while (n--) {
                auto node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
                line.push_back(node->left ? node->left->val : LONG_MAX);
                line.push_back(node->right ? node->right->val : LONG_MAX);
            }
            int i = -1, j = line.size();
            while (++i < --j) if (line[i] != line[j]) return false;
        }
        return true;
    }
};

//----------------------------------------------------------------------------

class Solution {
public:
    bool judge(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        return left->val == right->val && judge(left->right, right->left) && judge(left->left, right->right);
    }
    
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        return judge(root->left, root->right);
    }
};
