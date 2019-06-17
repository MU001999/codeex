/*
Q-URL: https://leetcode-cn.com/problems/robot-bounded-in-circle
*/

class Solution {
public:
    bool isRobotBounded(string instructions) {
        int start[] = {0, 0};
        int direction = 0;
        int directions[] = {0, 1, 1, 0, 0, -1, -1, 0};
        for (auto ins : instructions)
        {
            switch (ins)
            {
                case 'G':
                    start[0] += directions[direction];
                    start[1] += directions[direction + 1];
                    break;
                case 'L':
                    direction = (direction + 6) % 8;
                    break;
                default:
                    direction = (direction + 2) % 8;
                    break;
            }
        }
        if (direction || (start[0] == 0 && start[1] == 0)) return true;
        return false;
    }
};
