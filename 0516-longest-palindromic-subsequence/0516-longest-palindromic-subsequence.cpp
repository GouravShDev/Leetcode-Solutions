class Solution {
public:
    int solve(string &s1, string &s2, int i , int j, vector<vector<int>> &dp){
        if(i == s1.size() || j == s2.size()) return 0;
        int ans = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            ans = solve(s1, s2, i+1, j+1,dp) + 1;
        }
        ans = max({ans, solve(s1, s2, i+1, j,dp) , solve(s1, s2, i, j+1,dp)});
        return dp[i][j]= ans;
    }
    int longestPalindromeSubseq(string s) {
        string s2 = s;
        reverse(s2.begin(), s2.end());
        vector<vector<int>> dp(s.size() , vector<int>(s.size(), -1));
        return solve(s, s2, 0 ,0, dp);
    }
};