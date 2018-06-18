/*
Q-URL: https://leetcode-cn.com/problems/h-index/description/
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        
        size_t len = citations.size();
        if (!len) return len;
        
        size_t i = 0;
        for (i = 0; i < len; ++i)
            if (citations[i] < i + 1) 
                return i;
        return len;
    }
};