class Solution {
public:
    int solve(vector<pair<int,int>> &strs , int index, int m , int n,vector<vector<vector<int>>> &dp){
        if(m < 0 ) return INT_MIN;
        if(n < 0) return INT_MIN;
        if(index == strs.size()) return 0;
        if(dp[index][m][n] != -1) return dp[index][m][n];
        int ans = 0;
        int pick = 1 + solve(strs, index+1, m - strs[index].first, n - strs[index].second,dp);
        int notPick = solve(strs, index+1, m , n,dp);
        ans = max(pick, notPick);
        //cout<<index<<" "<<m<<" "<<n<<endl;
        return dp[index][m][n] = ans;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> strCount;
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>>(m+1 , vector<int>(n+1 , -1)));
        for(auto &str : strs){
            int oneCount = 0;
            int zeroCount = 0;
            for(auto &s : str){
                if(s == '0') zeroCount++;
                if(s == '1') oneCount++;
            }
            strCount.push_back({zeroCount, oneCount});
        }
        return solve(strCount, 0, m , n,dp);
    }
};