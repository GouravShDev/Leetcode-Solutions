class Solution {
public:
    int delta[5] = {0,1,0,-1,0};
    int mod = 1e9 + 7;
    int solve(vector<vector<int>> &grid, int i , int j, vector<vector<int>> &dp){
        //cout<<i<<j<<endl;
        int count = 1;
        if(dp[i][j] != -1) return dp[i][j];
        for(int k = 0 ; k < 4; k++){
            int newI = i + delta[k];
            int newJ = j + delta[k+1];
            if(newI < 0 || newJ < 0 || newI >= grid.size() || newJ >= grid[0].size() || grid[newI][newJ] <= grid[i][j]) continue;
            count = (count + solve(grid, newI, newJ,dp)) % mod;
        }
        return dp[i][j] = count;
    }
    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(), -1));
        int ans = 0;
        for(int i = 0 ;i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                
                ans = (ans +   solve(grid,i, j, dp)) % mod;
            }
        }
        return ans;
    }
};

// 1 2 3

// dp[i] = 1 + 2 * dp[node]

// 1
// 2 + 1 = 3
// 