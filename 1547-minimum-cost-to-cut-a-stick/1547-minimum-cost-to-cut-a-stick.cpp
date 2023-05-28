class Solution {
public:
    int solve(vector<int> &cuts, int i , int j, vector<vector<int>> &dp){
        //cout<<i<<" "<<j<<endl;
        if(i >j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int minx = 1e8;
        for(int index = i; index <= j; index++){
            int x = (cuts[j+1] -cuts[i-1]) + solve(cuts ,i , index-1,dp) + solve(cuts, index+1, j,dp);
            // cout<<x<<endl;
            minx= min(minx, x);
        }
        // cout<<i<<" "<<j<<" "<<minx<<endl;
        return dp[i][j] = minx;
    }
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        int c = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        vector<vector<int>> dp(c+1, vector<int>(c+1, -1));
        return solve(cuts, 1, c,dp);
    }
};