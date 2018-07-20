/*
Q-URL: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
# BEATS 99.94%
*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root, int n = 0) {
        queue<TreeNode*> q;
        vector<vector<int>> lines;
        if (!root) return lines;
        q.push(root);
        while ((n = q.size())) {
            vector<int> line;
            while (n--) {
                auto node = q.front();
                q.pop();
                line.push_back(node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            lines.push_back(line);
        }
        return lines;
    }
};
