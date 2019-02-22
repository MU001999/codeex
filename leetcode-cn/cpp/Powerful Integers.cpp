/*
Q-URL: https://leetcode-cn.com/problems/powerful-integers/
*/

class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> res;
        
        if (x > y) swap(x, y);
        
        int l = 1, r = 1;
        
        while (r <= bound)
        {
            while (r + l <= bound)
            {
                res.insert(r + l);
                if (x == 1) break;
                l *= x;
            }
            if (y == 1) break;
            l = 1;
            r *= y;
        }
        
        return vector<int>(res.begin(), res.end());
    }
};
