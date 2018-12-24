/*
Q-URL: https://leetcode-cn.com/problems/implement-queue-using-stacks/
# BEATS 100%
*/

class MyQueue {
private:
    stack<int> s;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        stack<int> _s;
        while (!s.empty())
        {
            auto _ = s.top(); s.pop();
            _s.push(_);
        }
        auto res = _s.top(); _s.pop();
        while (!_s.empty())
        {
            auto _ = _s.top(); _s.pop();
            s.push(_);
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        stack<int> _s;
        while (!s.empty())
        {
            auto _ = s.top(); s.pop();
            _s.push(_);
        }
        auto res = _s.top();
        while (!_s.empty())
        {
            auto _ = _s.top(); _s.pop();
            s.push(_);
        }
        return res;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */
