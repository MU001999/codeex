/*
Q-URL: https://leetcode-cn.com/problems/reverse-only-letters/submissions/
*/

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0, r = S.size() - 1;
        do {
            while (l < S.size() and !isalpha(S[l])) {
                ++l;
            }
            while (r >= 0 and !isalpha(S[r])) {
                --r;
            }
            if (l < r) {
                swap(S[l++], S[r--]);
            }
        } while (l < r);
        return S;
    }
};
