class Solution {
public:
    int solve(vector<vector<int>> &dp , int start ,int end, vector<vector<int>>  &dp2){
        if(start == dp.size()){
            return 0;
        }
        if(end == dp.size())return 1e7;
        if(dp2[start][end] != -1) return dp2[start][end];
        int ans = INT_MAX;
        // cut
        if(dp[start][end])
            ans = min(ans, 1 + solve(dp , end+1, end+1,dp2));
        // not cut
        ans = min(ans, solve(dp, start, end+1,dp2));
        return dp2[start][end] = ans;
        
    }
    int minCut(string s) {
        vector<vector<int>> dp(s.size() , vector<int>(s.size()));
        for(int i =0 ;i < s.size() ; i++){
            int l = i;
            int r = i;
            while(l >= 0 && r < s.size()&& s[l] == s[r]){
                dp[l][r] = 1;
                l--;
                r++;
            }
            l = i;
            r = i+1;
            while(l >= 0 && r < s.size() && s[l] == s[r]){
                dp[l][r] = 1;
                l--;
                r++;
            }
            
        }
        // for(int i = 0 ; i < s.size() ; i++){
        //     for(int j = 0 ; j< s.size() ; j++){
        //         cout<<dp[i][j]<< " ";
        //     }
        //     cout<<endl;
        // }
        vector<vector<int>> dp2(s.size(), vector<int> (s.size(), -1));
        return solve(dp, 0 , 0,dp2)-1;
        // return 0;
        
    }
};