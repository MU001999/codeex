/*
Q-URL: https://leetcode-cn.com/problems/group-anagrams/description/
# ALL BEATS 100%
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> mp;
        for (auto &str : strs) {
            auto key = str; sort(key.begin(), key.end());
            if (mp.find(key) == mp.end()) {
                mp[key] = res.size();
                res.push_back({str});
            } else res[mp[key]].push_back(str);
        }
        return res;
    }
};

//----------------------------------------------------------------

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mps;
        for(string s: strs){
            string ss = s; sort(s.begin(),s.end());
            mps[s].push_back(ss);
        }
        for(auto m: mps) res.push_back(m.second);
        return outs;
    }
};
