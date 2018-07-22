/*
Q-URL: https://leetcode-cn.com/problems/min-stack/description/
*/

class MinStack {
private:
    vector<int> data;
    int mn;
    
public:
    /** initialize your data structure here. */
    MinStack() : mn(INT_MAX) {}
    
    void push(int x) {
        mn = min(x, mn);
        data.push_back(x);
    }
    
    void pop() {
        if (data.size() == 1) mn = INT_MAX;
        else if (data.back() == mn) mn = *(min_element(data.begin(), data.end()-1));
        data.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return mn;
    }
};
