/*
Q-URL: https://leetcode-cn.com/problems/minimum-genetic-mutation/
# BEATS 100%
*/

class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        set<string> heads{start}, tails{end}, bankSet(bank.begin(), bank.end());

        if (!bankSet.count(end)) {
            return -1;
        }

        constexpr char chrs[] = { 'A', 'C', 'G', 'T' };

        int rounds = 0;
        while (!heads.empty() && !tails.empty()) {
            if (heads.size() > tails.size()) {
                swap(heads, tails);
            }

            set<string> temps;

            for (auto str : heads) {
                if (tails.count(str)) {
                    return rounds;
                }
                for (size_t i = 0; i < str.size(); ++i) {
                    char old = str[i];
                    for (auto chr : chrs) {
                        if (old != chr) {
                            str[i] = chr;
                            if (bankSet.count(str)) {
                                temps.insert(str);
                            }
                        }
                    }
                    str[i] = old;
                }
            }

            swap(heads, temps);
            ++rounds;
        }

        return -1;
    }
};
