class Solution {
public:
    int solve(vector<vector<int>> &matrix, int i ,int j ,vector<vector<int>> &dp){
        if(i == matrix.size())return 0;
        if(dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = matrix[i][j] +
            min({solve(matrix, i+1, j,dp), solve(matrix,i+1, max(0,j-1),dp) , solve(matrix,i+1, min((int) matrix.size()-1, j+1), dp)});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n , vector<int> (m , -1));
        int ans = INT_MAX;
        for(int i =0 ; i < matrix[0].size(); i++)
            ans = min(ans, solve(matrix, 0, i,dp));
        return ans;
    }
};