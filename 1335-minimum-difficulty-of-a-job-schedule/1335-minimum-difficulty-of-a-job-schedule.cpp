class Solution {
public:
    int solve(vector<int>& diff, int index, int d, int curMx,vector<vector<vector<int>>> &dp){
        if(index == diff.size()) return 1e6;
        if(d == 1){
            return *max_element(diff.begin() + index, diff.end());
        }
        if(dp[index][d][curMx] != -1 )return dp[index][d][curMx];
        curMx = max(curMx, diff[index]);
        int ans = 0;
        // not pick
        ans = solve(diff, index+1, d, curMx,dp);
        
        // pick
        ans = min(ans, curMx + solve(diff, index+1, d-1, 0,dp));
        return dp[index][d][curMx] = ans;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        vector<vector<vector<int>>> dp(jobDifficulty.size() , vector<vector<int>>(d+1, vector<int>(1e3+1,-1)));
        if(d > jobDifficulty.size()) return -1;
        return solve(jobDifficulty, 0 , d, 0,dp);
    }
};