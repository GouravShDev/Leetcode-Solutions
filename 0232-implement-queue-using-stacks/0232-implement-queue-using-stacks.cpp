class MyQueue {
private:
    void move(){
        if(popStk.empty()){
            while(!pushStk.empty()){
                popStk.push(pushStk.top());
                pushStk.pop();
            }
        }
    }
public:
    stack<int> pushStk;
    stack<int> popStk;
    
    MyQueue() {
        
    }
    
    void push(int x) {
        pushStk.push(x);
    }
    
    int pop() {
        move();
        int elem = popStk.top();
        popStk.pop();
        return elem;
    }
    
    int peek() {
        move();
        return popStk.top();
    }
    
    bool empty() {
        return popStk.empty() && pushStk.empty();
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