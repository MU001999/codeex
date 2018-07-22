/*
Q-URL: https://leetcode-cn.com/problems/count-primes/description/
*/

class Solution {
public:
    int countPrimes(int n, int i = 1, int j = 0, int res = 0) {
        if (n < 2) return 0;
        vector<bool> record(n, true);
        record[0] = record[1] = false;
        while (++i < n) {
            if (record[i]) ++res;
            else continue;
            j = i;
            while ((j += i) < n) record[j] = false;
        }
        return res;
    }
};
