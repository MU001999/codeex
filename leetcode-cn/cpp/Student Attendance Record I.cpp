/*
Q-URL: https://leetcode-cn.com/problems/student-attendance-record-i
*/

class Solution {
public:
    bool checkRecord(string s) {
        bool hasA = false;
        int hasL = 0;
        for (auto c : s)
        {
            if (c == 'A')
            {
                if (hasA) return false;
                else hasA = true;
                hasL = 0;
            }
            else if (c == 'L')
            {
                if (hasL == 2) return false;
                else ++hasL;
            }
            else hasL = 0;
        }
        return true;
    }
};