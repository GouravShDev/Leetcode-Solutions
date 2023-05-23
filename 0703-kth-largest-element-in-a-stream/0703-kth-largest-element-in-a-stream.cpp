class KthLargest {
public:
    priority_queue<int, vector<int> ,greater<int>> pq;
    int mxSize;
    KthLargest(int k, vector<int>& nums) {
        mxSize = k;
        for(auto & it : nums){
            pq.push(it);
        }
        while(pq.size() > k){
            pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() > mxSize) pq.pop();
        return pq.top();
    }
};

// 5 4 2

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */