/*
Q-URL: https://leetcode-cn.com/problems/insert-delete-getrandom-o1/
# BEATS 98.24%
*/

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> maps;
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {}
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (maps.count(val)) return false;
        maps[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!maps.count(val)) return false;
        maps[nums.back()] = maps[val];
        swap(nums[maps[val]], nums.back());
        nums.pop_back();
        maps.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
