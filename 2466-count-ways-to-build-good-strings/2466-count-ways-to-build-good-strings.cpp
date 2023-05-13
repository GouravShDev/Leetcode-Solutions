class Solution {
public:
    int mod = 1e9 + 7;
    int solve(int len , int low ,int high , int zero , int one, vector<int> &dp){
        if(len > high) return 0;
        if(dp[len] != -1 )return dp[len];
        int onePicked = solve(len + one , low , high, zero, one ,dp);
        int zeroPicked = solve(len + zero , low , high, zero, one ,dp);
        return dp[len] = (((len >= low && len <= high) ? 1 : 0) * 1ll + onePicked + zeroPicked) % mod ;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1 ,-1);
        return solve(0 , low , high , zero , one,dp);
    }
};