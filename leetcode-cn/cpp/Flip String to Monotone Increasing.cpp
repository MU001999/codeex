/*
Q-URL: https://leetcode-cn.com/problems/flip-string-to-monotone-increasing
*/

class Solution {
public:
    int minFlipsMonoIncr(string S) {
        vector<int> pres{0};
        for (auto c : S) {
            pres.push_back(pres.back() + (c == '0' ? 0 : 1));
        }
        int result = INT_MAX;
        for (int i = 0; i < pres.size(); ++i) {
            int flip = pres[i] +
                S.size() - i - pres.back() + pres[i];
            result = min(result, flip);
        }
        return result;
    }
};
