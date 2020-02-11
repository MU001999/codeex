/*
Q-URL: https://leetcode-cn.com/problems/asteroid-collision/
*/

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> result;
        for (auto asteroid : asteroids) {
            if (asteroid < 0) {
                if (result.empty() || result.back() < 0) {
                    result.push_back(asteroid);
                } else {
                    bool insert = true;
                    while (!result.empty() and result.back() > 0) {
                        if (result.back() > -asteroid) {
                            insert = false;
                            break;
                        } else if (result.back() < -asteroid) {
                            result.pop_back();
                        } else {
                            result.pop_back();
                            insert = false;
                            break;
                        }
                    }
                    if (insert) {
                        result.push_back(asteroid);
                    }
                }
            } else {
                result.push_back(asteroid);
            }
        }
        return result;
    }
};