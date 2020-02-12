/*
Q-URL: https://leetcode-cn.com/problems/replace-words
*/

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string result;

        unordered_set<string> roots;
        for (auto &root : dict) {
            roots.insert(root);
        }

        sentence += ' ';
        string temp;
        for (int i = 0; i < sentence.size(); ++i) {
            if (sentence[i] == ' ') {
                result += temp + ' ';
                temp.clear();
            } else {
                temp += sentence[i];
                if (roots.count(temp)) {
                    result += temp + ' ';
                    temp.clear();
                    while (sentence[i] != ' ') {
                        ++i;
                    }
                }
            }
        }
        result.pop_back();

        return result;
    }
};
