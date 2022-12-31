class Solution {
public:
    int solve(vector<vector<int>> &grid, int i, int j,vector<vector<int>> &dp ){
        int n = grid.size();
        int m = grid[0].size();
        if(i == n || j == m || grid[i][j] == 1) return 0;
        if(i == n-1 && j == m-1 )return 1;
        if(dp[i][j]!= -1)return dp[i][j];
        return dp[i][j] = solve(grid, i  +1, j,dp) + solve(grid, i, j +1,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m,-1));
        if(obstacleGrid[n-1][m-1] == 1) return 0;
        return solve(obstacleGrid, 0, 0,dp);
    }
};