/*
Q-URL: https://leetcode-cn.com/problems/coin-change/
# BEATS 88.77%
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> res(amount + 1, amount + 1); res[0] = 0;
        sort(coins.begin(), coins.end());
        for (auto i = 1; i <= amount; ++i) for (auto &coin: coins) if (coin <= i) res[i] = min(res[i], res[i-coin] + 1); else break;
        return (res[amount] == amount + 1) ? -1 : res[amount];
    }
};
