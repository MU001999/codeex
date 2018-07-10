/*
Q-URL: https://www.codewars.com/kata/diophantine-equation/train/cpp

Hint: Pell Equation
*/

#include <vector>
#include <utility>
#include <cmath>

class Dioph
{
    public:
    static std::vector<std::pair<long, long>> solEquaStr(long long n){
        std::vector<std::pair<long,long>> ans;
        long long b;
        for (long long a = 1; a * a <= n; ++a){
            if (n % a) continue;
            b = n/a;
            if ((b - a) % 4) continue;
            ans.push_back(std::make_pair((a + b) / 2, (b - a) / 4));
        }
        return ans;
    }
};
