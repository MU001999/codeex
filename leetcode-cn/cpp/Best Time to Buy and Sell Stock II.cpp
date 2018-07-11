/*
Q-URL: https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/description/
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int result = 0;
        for (int i = 1; i < prices.size(); ++i)
            if (prices[i] > prices[i-1]) 
                result += prices[i] - prices[i-1];
        return result;
    }
};
