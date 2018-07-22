/*
Q-URL: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/description/
# BEATS 100%
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (!prices.size()) return 0;
        int mn = prices[0], result = 0;
        for (int &price : prices) if (price > mn) result = max(price - mn, result); else mn = price;
        return result;
    }
};
