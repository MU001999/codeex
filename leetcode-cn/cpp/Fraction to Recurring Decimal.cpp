/*
Q-URL: https://leetcode-cn.com/problems/fraction-to-recurring-decimal/
# BEATS 100%
*/

class Solution {
public:
    string fractionToDecimal(int _numerator, int _denominator) {
        if (_numerator == 0) return "0";
        
        auto pre = ((_numerator < 0) ^ (_denominator < 0)) ? "-" : "";
        long long numerator = abs((long long)_numerator), denominator = abs((long long)_denominator);
        
        if (numerator % denominator == 0) return pre + to_string(numerator / denominator);
        string res = pre + to_string(numerator / denominator) + ".";
        
        unordered_map<int, int> pos;
        pos[numerator %= denominator] = res.size();
        
        while (numerator % denominator)
        {
            numerator *= 10;
            res += to_string(numerator / denominator);
            auto c = numerator % denominator;
            if (pos.count(c))
            {
                res.insert(pos[c], "(");
                res.push_back(')');
                break;
            }
            else 
            {
                pos[c] = res.size();
                numerator = c;
            }
        }
        return res;
    }
};
