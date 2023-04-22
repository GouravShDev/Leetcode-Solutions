class Solution {
public:
    int lcs(string &s1, string &s2, int i, int j , vector<vector<int>> &dp){
        if(i == s1.size() || j == s2.size()) return 0;
        int ans = 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(s1[i] == s2[j]){
            ans = max(ans, 1 + lcs(s1, s2, i+1, j+1,dp));
        }
        ans = max(ans, lcs(s1, s2, i+1, j,dp));
        ans = max(ans, lcs(s1, s2, i, j+1,dp));
        return dp[i][j]= ans;
    }
    int minInsertions(string s) {
        string sr = s;
        reverse(sr.begin(), sr.end());
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        int l = lcs(s, sr, 0,0 , dp);
        return s.size() - l;
    }
};