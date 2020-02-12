/*
Q-URL: https://leetcode-cn.com/problems/guess-numbers/
*/

class Solution {
public:
    int game(vector<int>& guess, vector<int>& answer) {
        int result = 0;
        for (int i = 0; i < 3; ++i) {
            result += guess[i] == answer[i];
        }
        return result;
    }
};
