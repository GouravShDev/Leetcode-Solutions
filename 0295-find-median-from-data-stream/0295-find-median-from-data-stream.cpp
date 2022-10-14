class MedianFinder {
public:
    priority_queue<int> mxHeapLeft;
    priority_queue<int, vector<int>, greater<int>> mnHeapRight;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        mxHeapLeft.push(num);
        if(mxHeapLeft.size() - mnHeapRight.size() > 1){
            mnHeapRight.push(mxHeapLeft.top());
            mxHeapLeft.pop();
        }else if(!mnHeapRight.empty() && mxHeapLeft.top() > mnHeapRight.top()){
            int leftMx = mxHeapLeft.top();
            int rightMn = mnHeapRight.top();
            mxHeapLeft.pop();
            mnHeapRight.pop();
            mnHeapRight.push(leftMx);
            mxHeapLeft.push(rightMn);
        }
    }
    
    double findMedian() {
        if(mxHeapLeft.size() != mnHeapRight.size()){
            return mxHeapLeft.top();
        }
        return (double)(mnHeapRight.top() + mxHeapLeft.top())/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */