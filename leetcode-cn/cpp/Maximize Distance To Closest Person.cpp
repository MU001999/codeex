/*
Q-URL: https://leetcode-cn.com/problems/maximize-distance-to-closest-person
*/

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) 
    {
        int side = 0, mid = 0, now = 0, i = -1;
        while (++i < seats.size())
        {
            if (!i && !seats[i])
            {
                while (!seats[i])
                {
                    ++side;
                    ++i;
                }
            }
            else if (i == seats.size() - 1 && !seats[i])
            {
                side = max(side, ++now);
            }
            else if (seats[i])
            {
                mid = max(mid, now);
                now = 0;
            }
            else
            {
                ++now;
            }
        }
        
        return max(side, (mid - 1) / 2 + 1);
    }
};
