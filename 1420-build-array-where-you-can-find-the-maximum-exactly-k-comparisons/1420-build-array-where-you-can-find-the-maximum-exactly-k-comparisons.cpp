class Solution {
public:
    int mod = 1e9+7;
    int solve(int n, int m, int k, int curMx, vector<vector<vector<int>>> &dp){
        if(k < 0) return 0;
        if(n == 0){
            return k ==0;
        }
        if(curMx != -1 && dp[n][k][curMx] != -1) return dp[n][k][curMx];
        int ans =0 ;
        for(int i = 1 ; i <= m ; i++){
            ans = ((long long)ans  + solve(n-1, m, k - (curMx < i ? 1 : 0), max(curMx, i), dp)) % mod;
        }
        return curMx != -1 ? dp[n][k][curMx]  =  ans : ans;
    }
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k+1, vector<int>(101, -1)));
       return solve(n , m , k , -1,dp); 
    }
};