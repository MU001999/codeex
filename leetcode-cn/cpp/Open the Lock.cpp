/*
Q-URL: https://leetcode-cn.com/problems/open-the-lock/
*/

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int res = 0;
        
        unordered_map<string, bool> recod; recod["0000"] = true;
        queue<string> qs; qs.push("0000");
        
        while (!qs.empty())
        {
            decltype(qs) tmp;
            
            while (!qs.empty())
            {
                auto now = qs.front(); qs.pop();
                if (now == target) return res;
                else if (find(deadends.begin(), deadends.end(), now) != deadends.end()) continue;
                for (size_t i = 0; i < 4; ++i)
                {
                    auto _ = now, __ = now;
                    _[i] = (_[i] == '9') ? '0' : (_[i] + 1);
                    __[i] = (__[i] == '0') ? '9' : (__[i] - 1);
                    if (!recod.count(_))
                    {
                        recod[_] = true;
                        tmp.push(_);
                    }
                    if (!recod.count(__))
                    {
                        recod[__] = true;
                        tmp.push(__);
                    }
                }
            }
            
            qs = tmp;
            ++res;
        }
        
        return -1;
    }
};
