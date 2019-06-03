/*
Q-URL: https://leetcode-cn.com/problems/last-stone-weight
*/

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        while (stones.size() > 1)
        {
            auto a = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            auto b = stones.front();
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();

            if (a > b)
            {
                stones.push_back(a - b);
                push_heap(stones.begin(), stones.end());
            }
        }
        return stones.empty() ? 0 : stones.front();
    }
};
