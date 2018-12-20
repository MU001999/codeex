/*
Q-URL: https://leetcode-cn.com/problems/daily-temperatures/
*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res;
        stack<pair<int, int>> stck;
        
        for (int i = T.size() - 1; i >= 0; --i)
        {
            if (stck.empty())
            {
                res.push_back(0);
                stck.push({i, T[i]});
            }
            else if (T[i] < stck.top().second)
            {
                res.push_back(stck.top().first - i);
                stck.push({i, T[i]});
            }
            else
            {
                while (!stck.empty())
                {
                    auto v = stck.top(); stck.pop();
                    if (v.second > T[i])
                    {
                        res.push_back(v.first - i);
                        stck.push(v);
                        stck.push({i, T[i]});
                        break;
                    }
                }
                if (stck.empty()) 
                {
                    res.push_back(0);
                    stck.push({i, T[i]});
                }
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};
