/*
Q-URL: https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root) return "null";
        string res(to_string(root->val));
        vector<TreeNode*> layer = {root};
        while (layer.size())
        {
            auto head = layer[0];
            layer.erase(layer.begin());
            res += " " + (head->left ? to_string(head->left->val) : "null");
            res += " " + (head->right ? to_string(head->right->val) : "null");
            if (head->left) layer.push_back(head->left);
            if (head->right) layer.push_back(head->right);
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string tmp;
        ss >> tmp;
        if (tmp == "null") return NULL;
        
        vector<TreeNode*> layer;
        auto root = new TreeNode(stoi(tmp));
        layer.push_back(root);
        
        while (ss >> tmp)
        {
            if (tmp != "null")
            {
                layer[0]->left = new TreeNode(stoi(tmp));
                layer.push_back(layer[0]->left);
            }
            
            ss >> tmp;
            
            if (tmp != "null")
            {
                layer[0]->right = new TreeNode(stoi(tmp));
                layer.push_back(layer[0]->right);
            }
            
            layer.erase(layer.begin());
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
