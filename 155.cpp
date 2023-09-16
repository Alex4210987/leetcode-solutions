#include <stack>
using namespace std;

class MinStack {
public:
    stack<int> s;
    stack<int> min_s;
    MinStack() {}
    
    void push(int val) {
        s.push(val);
        if(min_s.empty() || val <= min_s.top()) min_s.push(val);
    }
    
    void pop() {
        if(s.top() == min_s.top()) min_s.pop();
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return min_s.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */