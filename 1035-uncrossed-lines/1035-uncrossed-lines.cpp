class Solution {
public:
    int solve(vector<int> n1, vector<int> n2, int i, int j, vector<vector<int>> &dp){
        if(i == n1.size() || j == n2.size()) return 0;
        int ans = 0;
        if(dp[i][j] != -1 )return dp[i][j];
        if(n1[i] == n2[j]){
            ans = max(ans, 1 + solve(n1, n2, i+1, j+1,dp));
        }
        ans = max({ans, solve(n1, n2, i, j+1,dp), solve(n1, n2, i+1, j,dp)});
        return dp[i][j] = ans;
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size() , vector<int>(nums2.size(), -1));
        return solve(nums1, nums2, 0, 0,dp);
    }
};