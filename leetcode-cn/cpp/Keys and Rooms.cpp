/*
Q-URL: https://leetcode-cn.com/problems/keys-and-rooms/
# BEATS 92.09%
*/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        visited[0] = true;
        
        queue<int> tovisit;
        tovisit.push(0);
        
        while (!tovisit.empty())
        {
            auto now = tovisit.front(); tovisit.pop();
            for (auto room: rooms[now])
            {
                if (!visited[room])
                {
                    visited[room] = true;
                    tovisit.push(room);
                }
            }
        }
        
        return find(visited.begin(), visited.end(), false) == visited.end();
    }
};
