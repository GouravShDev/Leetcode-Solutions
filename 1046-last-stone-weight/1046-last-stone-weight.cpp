class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto &stone : stones){
            pq.push(stone);
        }
        while(pq.size() > 1){
            int first = pq.top(); pq.pop();
            int second = pq.top(); pq.pop();
            if(first != second){
                pq.push(abs(first -second));   
            }
        }
        return pq.empty() ? 0 :  pq.top();
    }
};