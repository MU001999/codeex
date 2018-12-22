/*
Q-URL: https://leetcode-cn.com/problems/perfect-squares/
*/


class Solution {
public:
    int numSquares(int n, int res = 0) {
        int sq = sqrt(n);
        if (sq == 0) return 0;
        
        queue<pair<int, int>> qs;
        qs.push({0, sq});
        
        while (true)
        {
            decltype(qs) tmp;
            
            while (!qs.empty())
            {
                auto now = qs.front(); qs.pop();
                
                if (now.first == n) return res;
                
                for (int i = now.second; i >= 1; --i)
                {
                    if (now.first + i * i <= n)
                    {
                        tmp.push({now.first + i * i, i});
                    }
                }
            }
            
            qs = tmp;
            
            ++res;
        }
    }
};
