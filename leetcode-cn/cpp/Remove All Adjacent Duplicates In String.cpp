/*
Q-URL: https://leetcode-cn.com/problems/remove-all-adjacent-duplicates-in-string
*/

class Solution {
public:
    string removeDuplicates(string S) {
        if (S.empty()) return S;
        string res;
        for (auto c : S)
        {
            if (res.empty()) res.push_back(c);
            else if (res.back() == c) res.pop_back();
            else res.push_back(c);
        }
        return res;
    }
};
