class SeatManager {
public:
    priority_queue<int, vector<int> , greater<int>> pq;
    int current = 1;
    SeatManager(int n) {
    }
    
    int reserve() {
        if(pq.empty()){
            return current++;
        }
        int x = pq.top();
        pq.pop();
        return x;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */