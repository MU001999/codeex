/*
Q-URL: https://leetcode-cn.com/problems/swap-for-maximum-repeated-substring
# BEATS 98.76%
*/

class Solution {
public:
    int maxRepOpt1(string text) {
        if (text.size() < 2)
        {
            return text.size();
        }
        int res = 0;
        map<char, vector<pair<int, int>>> lens;
        for (int i = 0; i < text.size();)
        {
            auto j = i;
            auto c = text[j++];
            while (j < text.size() and text[j] == c)
            {
                ++j;
            }
            lens[c].push_back({i, j});
            res = max(res, j - i);
            i = j;
        }
        for (auto &chr_pairs : lens)
        {
            auto &ps = chr_pairs.second;
            if (ps.size() == 2)
            {
                for (int i = 0; i < ps.size(); ++i)
                {
                    res = max(res, ps[0].second - ps[0].first + 1);
                }
                if (ps[1].first == ps[0].second+1)
                {
                    res = max(res, ps[1].second - ps[0].first - 1);
                }
            }
            if (ps.size() > 2)
            {
                for (int i = 0; i < ps.size(); ++i)
                {
                    if (i > 0 and ps[i].first == ps[i-1].second + 1)
                    {
                        res = max(res, ps[i].second - ps[i-1].first);
                    }
                    else
                    {
                        res = max(res, ps[i].second - ps[i].first + 1);
                    }
                }
            }
        }
        return res;
    }
};
