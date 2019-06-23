/*
Q-URL: https://leetcode-cn.com/problems/long-pressed-name
# BEATS 100%
*/

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        auto it = typed.begin();
        for (auto c : name)
        {
            if (c == *it) ++it;
            else
            {
                while (c != *it && it != typed.end()) ++it;
                if (it == typed.end()) return false;
                else ++it;
            }
        }
        return true;
    }
};
