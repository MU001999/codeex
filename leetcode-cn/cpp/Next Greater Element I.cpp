/*
Q-URL: https://leetcode-cn.com/problems/next-greater-element-i
# BEATS 99.88%
*/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        map<int, int> cnts;
        stack<int> nums;
        for (auto num : nums2)
        {
            while (!nums.empty() && nums.top() < num)
            {
                cnts[nums.top()] = num;
                nums.pop();
            }
            nums.push(num);
        }
        vector<int> res;
        for (auto num : nums1)
        {
            if (cnts.count(num))
            {
                res.push_back(cnts[num]);
            }
            else
            {
                res.push_back(-1);
            }
        }
        return res;
    }
};
