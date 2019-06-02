/*
Q-URL: https://leetcode-cn.com/problems/walking-robot-simulation
*/

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int result = 0;
        
        set<pair<int, int>> obs;
        for (auto p : obstacles) obs.insert({p[0], p[1]});
        
        pair<int, int> start = {0, 0}, direction = {0, 1};
        for (auto command : commands)
        {
            switch (command)
            {
                case -2:
                    direction = {-direction.second, direction.first};
                    break;
                case -1:
                    direction = {direction.second, -direction.first};
                    break;
                default:
                    decltype(start) temp = {start.first + direction.first, start.second + direction.second};
                    while (command-- && !obs.count(temp))
                    {
                        start = temp;
                        result = max(result, start.first * start.first + start.second * start.second);
                        temp = {start.first + direction.first, start.second + direction.second};
                    }
                    break;
            }
        }
        
        return result;
    }
};
