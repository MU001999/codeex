/*
Q-URL: https://leetcode-cn.com/problems/koko-eating-bananas
*/

class Solution {
private:
    bool isOk(vector<int>& piles, int H, int K) {
        for (int i = piles.size() - 1; i >= 0; --i) {
            if ((H -= piles[i] / K + (piles[i] % K == 0 ? 0 : 1)) < 0) {
                return false;
            }
        }
        return true;
    }

public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1, r = 0;
        for (auto pile : piles) {
            r = max(r, pile);
        }
        while (l < r) {
            int m = (l + r) / 2;
            if (isOk(piles, H, m)) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};
auto _ = [](){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();
