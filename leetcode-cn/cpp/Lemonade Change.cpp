/*
Q-URL: https://leetcode-cn.com/problems/lemonade-change
# BEATS 97.50%
*/

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int cnts[3] = {0, 0, 0};
        for (auto bill : bills)
        {
            switch (bill)
            {
                case 5:
                    ++cnts[0];
                    break;
                case 10:
                    if (!cnts[0]) return false;
                    --cnts[0];
                    ++cnts[1];
                    break;
                default:
                    if (cnts[1] && cnts[0])
                    {
                        --cnts[0];
                        --cnts[1];
                        ++cnts[2];
                    }
                    else if (!cnts[1] && cnts[0] > 2)
                    {
                        cnts[0] -= 3;
                        ++cnts[2];
                    }
                    else return false;
                    break;
            }
        }
        return true;
    }
};
