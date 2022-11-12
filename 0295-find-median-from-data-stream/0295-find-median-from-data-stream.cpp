class MedianFinder {
public:
    // Mx Heap
    priority_queue<double> leftMx;
    
    // min Heap
    priority_queue<double, vector<double> , greater<double> > rightMn;
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        leftMx.push(num);
        
        // size diff <= 1
        if(leftMx.size() - rightMn.size() > 1){
            int x = leftMx.top();
            leftMx.pop();
            rightMn.push(x);
        }else if(!rightMn.empty() && leftMx.top() > rightMn.top() ){
            int lt = leftMx.top();
            leftMx.pop();
            int rt = rightMn.top();
            rightMn.pop();
            
            leftMx.push(rt);
            rightMn.push(lt);
        }
        
    }
    
    double findMedian() {
        if((leftMx.size() + rightMn.size()) % 2 == 0){
            return (leftMx.top() + rightMn.top()) / 2;
        }
        return leftMx.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */