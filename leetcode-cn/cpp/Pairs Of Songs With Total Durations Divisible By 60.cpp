/*
Q-URL: https://leetcode-cn.com/problems/pairs-of-songs-with-total-durations-divisible-by-60
*/

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int cnts[60] = { 0 };
        int res = 0;
        
        for (auto t : time)
        {
            t %= 60;
            res += cnts[(60 - t) % 60];
            ++cnts[t];
        }
        return res;
    }
};
