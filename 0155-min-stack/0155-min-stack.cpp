class MinStack {
private:
    vector<int> st1;
    vector<int> st2;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        st1.push_back(val);
        if(st2.empty()) st2.push_back(val);
        else st2.push_back(min(val, st2.back()));
    }
    
    void pop() {
        st1.pop_back();
        if(!st2.empty()) st2.pop_back();
    }
    
    int top() {
        return st1.back();
    }
    
    int getMin() {
        return st2.back();
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