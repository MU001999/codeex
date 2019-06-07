/*
Q-URL: https://leetcode-cn.com/problems/number-of-recent-calls
*/

class RecentCounter {
private:
    queue<int> pings;

public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        pings.push(t);
        while (pings.front() < t - 3000) pings.pop();
        return pings.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */