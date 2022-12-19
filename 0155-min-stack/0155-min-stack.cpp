#define ll long long
class MinStack {
public:
    stack<ll> stk;
    ll minElement = INT_MAX;
    MinStack() {
        // unsigned int k = -1;
        // cout<<k<<endl;
    }
    
    void push(int v) {
        ll val = v;
        if(stk.empty()){
            stk.push(val);
            minElement = val;
            return ;
        }
        if(val < minElement){
            ll modVal = 2 * val - minElement;
            minElement = val;
            stk.push(modVal);
        }else{
            stk.push(val);
        }
    }
    
    void pop() {
        if(stk.empty())return;
        if(stk.top() < minElement){
            ll orgVal = 2 * minElement - stk.top();
            minElement = orgVal;
            stk.pop();
        }else{
            stk.pop();
        }
    }
    
    int top() {
        if(stk.empty()) return -1;
        if(stk.top() < minElement) return minElement;
        return stk.top();
    }
    
    int getMin() {
        return minElement;
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