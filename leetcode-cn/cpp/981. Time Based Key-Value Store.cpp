/*
Q-URL: https://leetcode-cn.com/problems/time-based-key-value-store/
*/

class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        impl_map_[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto &vec = impl_map_[key];
        auto it = std::upper_bound(
            vec.begin(), vec.end(), 
            Elem{timestamp, string()}, 
            [] (const Elem &lhs, const Elem &rhs) { 
                return lhs.first < rhs.first; 
            }
        );

        if (it == vec.begin()) {
            return string();
        } else {
            return (it - 1)->second;
        }
    }

private:
    using Elem = pair<int, string>;
    unordered_map<string, vector<Elem>> impl_map_;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
