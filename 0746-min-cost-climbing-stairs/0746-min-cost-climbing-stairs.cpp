class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int prev_prev = cost[0];
        int prev = cost[1];
        for(int i = 2 ; i < cost.size() ; i++){
            int cur = cost[i] + min(prev , prev_prev);
            prev_prev = prev;
            prev = cur;
        }
        return min(prev, prev_prev);
     //   return prev; 
    }
};