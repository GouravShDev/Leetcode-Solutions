class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int steps, int arrLen, int index,vector<vector<int>> &dp){
        if(index < 0 || index == arrLen) return 0;
        if(steps == 0) return index == 0;
        if(dp[steps][index] != -1) return dp[steps][index];
        long long ans = 0;
        ans += solve(steps-1 , arrLen, index+1,dp);
        ans %= mod;
        ans += solve(steps-1, arrLen, index-1,dp);
           ans %= mod;
        ans += solve(steps-1, arrLen, index,dp);
           ans %= mod;
        return dp[steps][index] = ans;
    }
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps+1 , vector<int>(1e4, -1));
        return solve(steps, arrLen, 0,dp);
    }
};