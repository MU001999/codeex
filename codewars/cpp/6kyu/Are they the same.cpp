/*
Q-URL: https://www.codewars.com/kata/are-they-the-same/cpp
*/

#include <algorithm>

class Same
{
public:
    static bool comp(std::vector<int>, std::vector<int>);
};

bool Same::comp(std::vector<int> a, std::vector<int> b)
{
    for (auto &v : a) v = v * v;
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());
    return a == b;
}