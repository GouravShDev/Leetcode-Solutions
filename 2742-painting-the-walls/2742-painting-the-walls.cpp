class Solution {
public:
    int solve(vector<int> &cost , vector<int> &time, int index, int remain, vector<vector<int>> &dp){
        if(index == cost.size()) return remain <= 0 ? 0 : 1e9;
        if(remain < 0) return 0;
        if(dp[index][remain] != -1) return dp[index][remain];
        
        return dp[index][remain] = min(solve(cost, time, index+1, remain -1 - time[index],dp) + cost[index], solve(cost, time, index+1, remain, dp));
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        vector<vector<int>> dp(cost.size(), vector<int>(cost.size()+1,-1));
        return solve(cost , time, 0, cost.size() , dp);
    }
};