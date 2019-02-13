/*
Q-URL: https://leetcode-cn.com/problems/find-k-closest-elements/
*/

class Solution {
private:
    int helper(vector<int> &arr, int target, int left, int right)
    {
        if (left >= right) return arr[right] >= target ? right : 0;
        auto mid = (left + right) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) return helper(arr, target, mid + 1, right);
        else return helper(arr, target, left, mid);
    }
    
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        auto pos = helper(arr, x, 0, arr.size() - 1);
        int l = pos - 1, r = pos;
        while (r - l <= k)
        {
            if (l < 0) return vector<int>(arr.begin(), arr.begin() + k);
            else if (r > arr.size() - 1) return vector<int>(arr.end() - k, arr.end());
            else
            {
                auto lb = abs(arr[l] - x), rb = abs(arr[r] - x);
                if (rb < lb) ++r;
                else --l;
            }
        }
        return vector<int>(arr.begin() + l + 1, arr.begin() + r);
    }
};
