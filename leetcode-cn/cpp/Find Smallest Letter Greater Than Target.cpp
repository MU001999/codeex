/*
Q-URL: https://leetcode-cn.com/problems/find-smallest-letter-greater-than-target/
# BEATS 96.58%
*/


class Solution {
private:
    char helper(vector<char> &letters, char target, int left, int right)
    {
        if (left >= right) return letters[right] > target ? letters[right] : letters[0];
        auto mid = (left + right) / 2;
        if (letters[mid] <= target) return helper(letters, target, mid + 1, right);
        else return helper(letters, target, left, mid);
    }
    
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        return helper(letters, target, 0, letters.size() - 1);
    }
};

