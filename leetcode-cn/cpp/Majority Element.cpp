/*
Q-URL: https://leetcode-cn.com/problems/majority-element/
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 0, elem;
        for (auto &num: nums)
        {
            if (cnt == 0)
            {
                elem = num;
                ++cnt;
            }
            else if (num == elem) ++cnt;
            else --cnt;
        }
        return elem;
    }
};
