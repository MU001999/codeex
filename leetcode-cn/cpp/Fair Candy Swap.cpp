/*
Q-URL: https://leetcode-cn.com/problems/fair-candy-swap/
*/

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        bool swaped = false;
        if (A.size() > B.size()) {
            swap(A, B);
            swaped = true;
        }

        auto sumA = accumulate(A.begin(), A.end(), 0),
             sumB = accumulate(B.begin(), B.end(), 0);
        int diff = (sumB - sumA) / 2;

        unordered_map<int, bool> count;
        for (auto num : A) {
            count[num] = true;
        }
        for (auto num : B) {
            if (count.count(num - diff)) {
                return swaped ? vector<int>{ num, num - diff } : vector<int>{ num - diff, num };
            }
        }
        return { 0, 0 };
    }
};
