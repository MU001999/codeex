/*
Q-URL: https://leetcode-cn.com/problems/string-without-aaa-or-bbb/
*/

class Solution {
public:
    string strWithout3a3b(int A, int B, char a = 'a', char b = 'b') {
        string res;
        
        if (A < B) tie(A, B, a, b) = make_tuple(B, A, b, a);
        
        while (A || B)
        {
            if (A > 0) res += a, --A;
            if (A > B) res += a, --A;
            if (B > 0) res += b, --B;
            if (B > A) res += b, --B;
        }
        
        return res;
    }
};

