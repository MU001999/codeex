/*
Q-URL: https://www.codewars.com/kata/sum-by-factors/cpp
*/

#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <cmath>

class SumOfDivided
{
public:
    static std::string sumOfDivided(std::vector<int> &lst)
    {
        int sum, i;
        std::vector<int> inds;
        for (auto v : lst)
        {
            i = 2;
            while (abs(v) >= i)
            {
                while (v % i == 0)
                {
                    v /= i;
                    if (std::find(inds.begin(), inds.end(), i) == inds.end())
                    {
                        inds.push_back(i);
                    }
                }
                ++i;
            }
        }
        std::sort(inds.begin(), inds.end());
        std::string ret;
        for (auto &ind : inds)
        {
            sum = 0;
            for (auto &v : lst) 
            {
                if (v % ind == 0)
                {
                    sum += v;
                }
            }
            char temp[80];
            sprintf(temp, "(%d %d)", ind, sum);
            ret += temp;
        }
        return ret;
    }
};
