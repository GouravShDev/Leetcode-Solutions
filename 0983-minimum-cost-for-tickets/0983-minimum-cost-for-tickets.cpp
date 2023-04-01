class Solution {
public:
    int solve(vector<int> &days, vector<int>& costs, int index, int coveredDays, vector<int> &dp){
        if(index == days.size()){
            return 0;
        }
    if(coveredDays>=days[index]) return solve(days, costs, index+1, coveredDays,dp);
          if(dp[index] != -1) return dp[index];
        int ans = INT_MAX;
        
            ans= min(ans, costs[0] + solve(days, costs, index+1, days[index], dp) );
            ans= min(ans, costs[1] + solve(days, costs, index+1, days[index] + 6, dp));
            ans= min(ans, costs[2] + solve(days, costs, index+1, days[index] + 29, dp));
            return dp[index] =  ans;
        
        
         
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return solve(days, costs, 0 , 0, dp);
    }
};