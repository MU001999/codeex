/*
Q-URL: https://leetcode-cn.com/problems/search-suggestions-system/
*/

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> result = {{}};
        vector<string> lastAll;
        for (auto &product : products) {
            if (product[0] == searchWord[0]) {
                lastAll.push_back(product);
            }
        }
        for (int i = 0; i < min(3, (int)lastAll.size()); ++i) {
            result.back().push_back(lastAll[i]);
        }

        for (int i = 1; i < searchWord.size(); ++i) {
            vector<string> temp;
            for (auto &product : lastAll) {
                if (product[i] == searchWord[i]) {
                    temp.push_back(product);
                }
            }
            lastAll.swap(temp);
            result.push_back({});
            for (int i = 0; i < min(3, (int)lastAll.size()); ++i) {
                result.back().push_back(lastAll[i]);
            }
        }
        return result;
    }
};
