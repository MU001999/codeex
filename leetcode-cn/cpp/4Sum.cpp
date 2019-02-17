/*
Q-URL: https://leetcode-cn.com/problems/4sum/
*/

// 72ms
class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < int(nums.size() - 3); ++i) {
            for (int j = i + 1; j < int(nums.size() - 2); ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                int left = j + 1, right = nums.size() - 1;
                while (left < right) {
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                        res.insert(out);
                        ++left; --right;
                    } else if (sum < target) ++left;
                    else --right;
                }
            }
        }
        return vector<vector<int>>(res.begin(), res.end());
    }
};

// 144ms
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

