/*
Q-URL: https://leetcode-cn.com/problems/count-good-meals/
*/

class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        constexpr auto rem = 1000'000'000 + 7;
        int64_t result = 0;

        map<int, int> count;

        for (auto del : deliciousness) {
            ++count[del];
        }

        for (auto pir : count) {
            for (int i = 0; i < 23; ++i) {
                if (pir.first + pir.first == (1 << i)) {
                    result += (int64_t)pir.second * (pir.second - 1);
                } else if ((1 << i) >= pir.first) {
                    if (count.count((1 << i) - pir.first)) {
                        result += pir.second * count[(1 << i) - pir.first];
                    }
                }
            }
        }

        return (result / 2) % rem;
    }
};
