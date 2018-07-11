/*
Q-URL: https://leetcode-cn.com/problems/rotate-array/description/
*/

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        if (!nums.size()) return;
        k %= nums.size();
        while (k--) {
            nums.insert(nums.begin(), nums.back());
            nums.pop_back();
        }
    }
};

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (!k || nums.size() < 2) return;
        reverse(nums.begin()  , nums.end()    );
        reverse(nums.begin()  , nums.begin()+k);
        reverse(nums.begin()+k, nums.end()    );
    }
};
