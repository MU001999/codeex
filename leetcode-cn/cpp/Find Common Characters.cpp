/*
Q-URL: https://leetcode-cn.com/problems/find-common-characters/
# BEATS 100%
*/

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        if (A.empty())
        {
            return {};
        }

        int counts[26] = {0};
        for (auto chr : A[0])
        {
            ++counts[chr - 'a'];
        }
        for (size_t i = 1; i < A.size(); ++i)
        {
            int tmp_counts[26] = {0};
            for (auto chr : A[i])
            {
                ++tmp_counts[chr - 'a'];
            }

            for (int i = 0; i < 26; ++i)
            {
                counts[i] = min(counts[i], tmp_counts[i]);
            }
        }

        vector<string> result;
        for (char chr = 'a'; chr <= 'z'; ++chr)
        {
            for (int i = 0; i < counts[chr - 'a']; ++i)
            {
                result.emplace_back(1, chr);
            }
        }

        return result;
    }
};
