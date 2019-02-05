/*
Q-URL: https://leetcode-cn.com/problems/design-hashmap/
*/

class MyHashMap {
private:
    bool flags[1000000] = {0};
    int values[1000000] = {0};
    
public:
    /** Initialize your data structure here. */
    MyHashMap() { }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        flags[key] = true;
        values[key] = value;
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        return flags[key] ? values[key] : -1;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        flags[key] = false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap obj = new MyHashMap();
 * obj.put(key,value);
 * int param_2 = obj.get(key);
 * obj.remove(key);
 */
