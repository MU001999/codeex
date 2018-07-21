/*
Q-URL: https://leetcode-cn.com/problems/first-bad-version/description/
# BEATS 100%
*/

class Solution {
public:
    int search(long left, long right) {
        if (left >= right) return right;
        int mid = (left + right) / 2;
        return isBadVersion(mid) ? search(left, mid) : search(mid+1, right);
    }
    
    int firstBadVersion(int n) {
        if (isBadVersion(1)) return 1;
        return search(0, n);
    }
};
