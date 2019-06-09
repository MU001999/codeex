/*
Q-URL: https://leetcode-cn.com/problems/binary-prefix-divisible-by-5
*/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        
        unsigned long long num = 0;
        for (auto b : A)
        {
            res.push_back((num = (num * 2 + b) % 10) % 5 == 0);
        }
        
        return res;
    }
};
