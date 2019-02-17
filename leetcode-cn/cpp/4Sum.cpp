/*
Q-URL: https://leetcode-cn.com/problems/4sum/
*/

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        
        unordered_map<int, vector<pair<int, int>>> mps;
        for (int i = 0; i < nums.size(); ++i) for (int j = i + 1; j < nums.size(); ++j) mps[nums[i] + nums[j]].push_back({i, j});
        
        for (auto &mp : mps)
        {
            if (!mps.count(target-mp.first)) continue;
            for (auto &pair1 : mp.second) for (auto &pair2 : mps[target-mp.first])
            {
                if (pair1.second < pair2.first) res.insert({nums[pair1.first], nums[pair1.second], nums[pair2.first], nums[pair2.second]});
            }
        }
        
        return vector<vector<int>>(res.begin(), res.end());
    }
};

