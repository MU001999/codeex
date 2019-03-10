/*
Q-URL: https://leetcode-cn.com/problems/find-common-characters/
# BEATS 100%
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        vector<string> rest;
        map<char, int> cnts;
        
        for (auto c: A.front()) ++cnts[c];
        
        for (auto &s: A)
        {
            decltype(cnts) tmp;
            for (auto c: s) ++tmp[c];
            for (auto &cnt: cnts) cnt.second = min(tmp[cnt.first], cnt.second);
        }
        
        for (auto cnt: cnts) while (cnt.second--) rest.push_back(string() + cnt.first);
        
        return rest;
    }
};
