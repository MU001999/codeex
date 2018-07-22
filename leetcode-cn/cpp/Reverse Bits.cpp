/*
Q-URL: https://leetcode-cn.com/problems/reverse-bits/description/
# ALL BEATS 98.97%
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n, int l = -1, int r = 32) {
        bitset<32> bs(n);
        while (++l < --r) {
            bool temp = bs[l];
            bs[l] = bs[r];
            bs[r] = temp;
        }
        return bs.to_ulong();
    }
};

//--------------------------------------------------------------

class Solution {
public:
    uint32_t reverseBits(uint32_t n, uint32_t res = 0) {
        for (int i = 0; i < 32; ++i) {
            res <<= 1;
            res |= n & 1;
            n >>= 1;
        }
        return res;
    }
};
