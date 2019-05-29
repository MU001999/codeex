/*
Q-URL: https://leetcode-cn.com/problems/interval-list-intersections
*/

class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        auto ita = A.begin(), itb = B.begin();
        while (ita != A.end() && itb != B.end())
        {
            auto [sa, ea, sb, eb] = make_tuple((*ita)[0], (*ita)[1], (*itb)[0], (*itb)[1]);
            if (ea < sb) ++ita;
            else if (eb < sa) ++itb;
            else
            {
                result.push_back({max(sa, sb), min(ea, eb)});
                (ea < eb) ? ++ita : ++itb;
            }
        }
        return result;
    }
};