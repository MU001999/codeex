/*
Q-URL: https://leetcode-cn.com/problems/squares-of-a-sorted-array/
*/

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        
        auto r = lower_bound(A.begin(), A.end(), 0), l = r - 1;
        
        while (l >= A.begin() && r != A.end()) res.push_back((-*l < *r) ? pow(*l--, 2) : pow(*r++, 2));
        
        if (l < A.begin()) while (r != A.end()) res.push_back(pow(*r++, 2));
        else if (r == A.end())  while (l >= A.begin()) res.push_back(pow(*l--, 2));
        
        return res;
    }
};
