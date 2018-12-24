/*
Q-URL: https://leetcode-cn.com/problems/clone-graph/
# ALL BEATS 98.22%
*/


// Solution 1
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        
        stack<UndirectedGraphNode*> nodes;
        nodes.push(node);
        
        set<UndirectedGraphNode*> pres;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> maps;
        
        while (!nodes.empty())
        {
            auto node = nodes.top(); nodes.pop();
            
            if (pres.count(node)) continue;
            else pres.insert(node);
            
            auto &p = maps[node];
            if (!p) p = new UndirectedGraphNode(node->label);
            
            for(auto t: node->neighbors)
            {
                if (maps[t]) p->neighbors.push_back(maps[t]);
                else 
                {
                    maps[t] = new UndirectedGraphNode(t->label);
                    p->neighbors.push_back(maps[t]);
                    nodes.push(t);
                }
            }
        }
        
        return maps[node];
    }
};


// Solution 2
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) return node;
        
        stack<UndirectedGraphNode*> nodes;
        nodes.push(node);
        
        unordered_map<int, vector<int>> neibs;
        unordered_map<int, UndirectedGraphNode*> nnodes;
        
        while (!nodes.empty())
        {
            auto node = nodes.top(); nodes.pop();
            
            if (neibs.count(node->label)) continue;
            
            nnodes[node->label] = new UndirectedGraphNode(node->label);
            for(auto p: node->neighbors) 
            {
                neibs[node->label].push_back(p->label);
                nodes.push(p);
            }
        }
        
        for (auto &one: neibs)
        {
            for (auto lb: neibs[one.first]) nnodes[one.first]->neighbors.push_back(nnodes[lb]);
        }
        
        return nnodes[node->label];
    }
};
