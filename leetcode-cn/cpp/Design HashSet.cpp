/*
Q-URL: https://leetcode-cn.com/problems/design-hashset/
*/

class MyHashSet {
private:
    bool values[1000000] = {0};
    
public:
    /** Initialize your data structure here. */
    MyHashSet() { }
    
    void add(int key) {
        values[key] = true;
    }
    
    void remove(int key) {
        values[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return values[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */
 
