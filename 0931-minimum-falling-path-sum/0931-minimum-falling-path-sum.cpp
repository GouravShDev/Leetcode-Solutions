class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> dp = matrix[n-1];
        vector<int> prev = matrix[n-1];
        for(int i = n-2; i >= 0 ; i--){
            for(int j = 0 ; j < m; j++)
            {
                dp[j] = matrix[i][j] + min({prev[j], prev[max(0, j-1)], prev[min(m-1, j+1) ]});
            // cout<<dp[j]<<" ";
            }
            prev = dp;
            // cout<<endl;
        }
        return *min_element(dp.begin(), dp.end());
    }
};