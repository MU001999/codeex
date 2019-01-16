/*
Q-URL: https://leetcode-cn.com/problems/largest-perimeter-triangle
*/

class Solution {
public:
    int largestPerimeter(vector<int>& A) {
        sort(A.begin(), A.end());
        int i = A.size();
        while (--i > 1) if (A[i-1] + A[i-2] > A[i]) return A[i] + A[i-1] + A[i-2];
        return 0;
    }
};
