/*
Q-URL: https://leetcode-cn.com/problems/n-ary-tree-level-order-traversal
*/

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return {};
        vector<Node*> layer = { root };
        while (!layer.empty())
        {
            vector<Node*> temp;
            res.push_back({});
            for (auto node : layer)
            {
                res.back().push_back(node->val);
                temp.insert(temp.end(), node->children.begin(), node->children.end());
            }
            layer = temp;
        }
        return res;
    }
};
