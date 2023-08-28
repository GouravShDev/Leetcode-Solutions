class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
        
    }
    
    void push(int x) {
        move1();
        q1.push(x);
        move2();
    }
    void move1(){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
    }
    void move2(){
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop() {
        //move();
        int topElement = q1.front();
        q1.pop();
        return topElement;
        
    }
    
    int top() {
    //    move();
        return q1.front();
    }
    
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */