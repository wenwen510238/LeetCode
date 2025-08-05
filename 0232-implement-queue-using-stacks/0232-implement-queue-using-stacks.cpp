class MyQueue {
public:
    stack<int> inStk;
    stack<int> outStk;
    MyQueue() {
        
    }
    
    void push(int x) {
        inStk.push(x);
    }
    
    int pop() {
        moveIfNeeded();
        int val = outStk.top();
        outStk.pop();
        return val;
    }
    
    int peek() {
        moveIfNeeded();
        return outStk.top();
    }
    
    bool empty() {
        return inStk.empty() && outStk.empty();
    }
private:
    void moveIfNeeded() {
        if(outStk.empty()) {
            while(!inStk.empty()) {
                outStk.push(inStk.top());
                inStk.pop();
            }
        }
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */