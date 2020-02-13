/*
Q-URL: https://leetcode-cn.com/problems/longest-string-chain
*/

class Solution {
private:
    bool isPredecessor(const string& word1, const string& word2) {
        bool hasSkip = false;
        for (int i = 0, j = 0; i < word1.size(); ++i, ++j) {
            if (word1[i] != word2[j]) {
                if (hasSkip) {
                    return false;
                } else {
                    hasSkip = true;
                    --i;
                }
            }
        }
        return true;
    }

public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        for (auto &word : words) {
            sort(word.begin(), word.end());
        }
        vector<int> counts(words.size(), 1);
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (words[j].size() == words[i].size() - 1) {
                    if (isPredecessor(words[j], words[i])) {
                        counts[i] = max(counts[i], counts[j] + 1);
                    }
                }
            }
        }
        return *max_element(counts.begin(), counts.end());
    }
};
