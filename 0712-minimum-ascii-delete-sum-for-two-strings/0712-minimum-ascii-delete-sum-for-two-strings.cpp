class Solution {
public:
    int lcs(string &s1, string &s2, int i ,int j, vector<vector<int>> &dp ){
        if( i == s1.size() || j == s2.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = max(lcs(s1, s2 , i+1, j, dp) , lcs(s1, s2, i, j+1,dp));
        if(s1[i] == s2[j]){
            ans = max(ans, s1[i] + lcs(s1, s2, i+1, j+1,dp));
        }
        return dp[i][j] = ans;
    }
    int getAsciiSum(string &s){
        int sum =0 ;
        for(auto c : s){
            sum += c;
        }
        return sum;
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size() ,vector<int>(s2.size(),-1));
         return getAsciiSum(s1) + getAsciiSum(s2) -  2 * lcs(s1, s2, 0 , 0,dp);
    }
};