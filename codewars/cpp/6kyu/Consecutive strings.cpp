/*
Q-URL: https://www.codewars.com/kata/consecutive-strings/cpp
*/

#include <functional>
#include <numeric>
#include <string>
#include <vector>

class LongestConsec
{
public:
    static std::string longestConsec(const std::vector<std::string> &strings, int k)
    {
        k = std::max(k, 0);
        std::string longest;
        for (size_t i = k; i <= strings.size(); i += 1)
        {
            auto begin = std::next(strings.begin(), i - k);
            auto end = std::next(begin, k);
            std::string s = std::accumulate(begin, end, std::string());
            if (s.length() > longest.length())
            {
                longest = s;
            }
        }
        return longest;
    }
};