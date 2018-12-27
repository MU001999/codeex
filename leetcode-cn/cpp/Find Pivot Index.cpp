/*
Q-URL: https://leetcode-cn.com/problems/find-pivot-index/
*/


// Solution 1
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pre = 0;
        vector<int> nexcnts;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            nexcnts.push_back(nexcnts.empty() ? 0 : nexcnts.back() + nums[i + 1]);
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i) pre += nums[i - 1];
            if (pre == nexcnts[nexcnts.size() - i - 1]) return i;
        }
        return -1;
    }
};


// Solution 2
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        auto sum = accumulate(nums.begin(), nums.end(), 0), pre = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (pre * 2 == sum - nums[i]) return i;
            pre += nums[i];
        }
        return -1;
    }
};
