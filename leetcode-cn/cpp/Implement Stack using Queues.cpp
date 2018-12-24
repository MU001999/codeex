/*
Q-URL: https://leetcode-cn.com/problems/implement-stack-using-queues/
# BEATS 100%
*/

class MyStack {
private:
    queue<int> q;
    
public:
    /** Initialize your data structure here. */
    MyStack() {}
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        auto res = q.back();
        queue<int> _q;
        while (q.size() != 1)
        {
            auto _ = q.front(); q.pop();
            _q.push(_);
        }
        q = _q;
        return res;
    }
    
    /** Get the top element. */
    int top() {
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */
