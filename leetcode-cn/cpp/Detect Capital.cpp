/*
Q-URL: https://leetcode-cn.com/problems/detect-capital
*/

class Solution {
public:
    bool detectCapitalUse(string word) {
        if (word.empty())
        {
            return true;
        }
        int cnt = 0;
        for (auto w : word)
        {
            if ('A' <= w && w <= 'Z')
            {
                ++cnt;
            }
        }
        return cnt == 0 || cnt == word.size() || (cnt == 1 && ('A' <= word.front() && word.front() <= 'Z'));
    }
};
