/*
Q-URL: https://leetcode-cn.com/problems/path-in-zigzag-labelled-binary-tree/submissions/
*/

class Solution {
private:
    int parent(int num) {
        num /= 2;
        int n = 1;
        while (n <= num) {
            n <<= 1;
        }
        return n / 2 + n - num - 1;
    }

public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> result;
        while (label != 0) {
            result.push_back(label);
            label = parent(label);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
