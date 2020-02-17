/*
Q-URL: https://leetcode-cn.com/problems/integer-replacement
*/

class Solution {
public:
    int integerReplacement(int n) {
        int result = 0;
        vector<uint32_t> layer = {n};
        while (!layer.empty()) {
            vector<uint32_t> temp;
            for (auto num : layer) {
                if (num == 1) {
                    return result;
                } else if (num % 2 == 0) {
                    temp.push_back(num / 2);
                } else {
                    temp.push_back(num + 1);
                    temp.push_back(num - 1);
                }
            }
            layer = move(temp);
            ++result;
        }
        return result;
    }
};
