#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <sstream>

class WeightSort
{
public:
    static std::string orderWeight(const std::string &strng)
    {
        std::stringstream ss;
        ss.str(strng);
        std::vector<std::string> weights;
        std::string temp;
        while (ss >> temp) weights.push_back(temp);
        std::stable_sort(weights.begin(), weights.end());
        std::stable_sort(weights.begin(), weights.end(), [](const std::string &a, const std::string &b)
        {
            auto _sum = [](std::string str)
            {
                int _tmp = 0;
                for (auto &chr : str) _tmp += chr - '0';
                return _tmp;
            };
            return _sum(a) < _sum(b);
        });
        std::string result;
        for (auto iter = weights.begin(); iter != weights.end(); ++iter)
            result += (iter == weights.begin()) ? (*iter) : (" " + *iter);
        return result;
    }
};
