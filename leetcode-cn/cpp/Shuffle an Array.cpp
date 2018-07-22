/*
Q-URL: https://leetcode-cn.com/problems/shuffle-an-array/description/
*/

class Solution {
private:
    vector<int> origin;
    vector<int> nums;
    
public:
    Solution(vector<int> nums) : origin(nums), nums(nums) {}
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        nums = origin;
        return nums;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        random_shuffle(nums.begin(), nums.end());
        return nums;
    }
};
