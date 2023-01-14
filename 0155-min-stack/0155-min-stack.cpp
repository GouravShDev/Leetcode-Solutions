class MinStack {
public:
    stack<long long> stk;
    long long curMin;
    MinStack() {
        
    }
    
    void push(int v) {
        long long val=  v;
        if(stk.empty()){
            stk.push(val);
            curMin = val;
        }else{
            if(curMin < val){
                stk.push(val);
            }else{
                stk.push((long long) 2 * val - curMin);
                curMin = val;
            }
        }
    }
    
    void pop() {
        if(stk.top() < curMin){
            curMin = (long long) (2 * curMin - stk.top());
            stk.pop();
        }else{
            stk.pop();
        }
    }
    
    int top() {
        if(stk.top() < curMin){
            return curMin;
        }else return stk.top();
    }
    
    int getMin() {
        return curMin;
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