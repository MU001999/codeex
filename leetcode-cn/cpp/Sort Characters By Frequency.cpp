/*
Q-URL: https://leetcode-cn.com/problems/sort-characters-by-frequency/
*/


class Solution {
public:
    string frequencySort(string s) {
        string res;
        
        unordered_map<char, int> cnt;
        for (auto c : s) ++cnt[c];
        
        unordered_map<int, string> mps;
        
        for (auto &pair : cnt) mps[pair.second] += string(pair.second, pair.first);
        
        vector<string> tmp(s.size(), "");
        for (auto &pair : mps) tmp[pair.first - 1] = pair.second;
        for (auto it = tmp.rbegin(); it != tmp.rend(); ++it) res += *it;
        
        return res;
    }
};
