class Solution {
public:
//     int mod= 1e9 + 7;
//     void solve(int n, int minProfit, vector<int> &group , vector<int> &profit, int index, int sum , int &ans, vector<vector<int>> &dp){//cout<<sum<<endl;
//         if(n < 0 ) return;
//         if(index == profit.size()) {
            
//             if(sum >= minProfit){
//             ans = ((ans * 1ll) + 1) % mod;
//         }
//             return;
//         }
//         // if(dp[index][sum] != -1) return dp[index][sum];
        
//         solve(n-group[index], minProfit, group, profit, index+1, sum + profit[index],ans);
           
//         solve(n, minProfit, group, profit, index+1, sum,ans);
//     }
    int profitableSchemes(int G, int P, vector<int>& group, vector<int>& profit) {
        vector<vector<int>> dp(P + 1, vector<int>(G + 1, 0));
        dp[0][0] = 1;
        int res = 0, mod = 1e9 + 7;
        for (int k = 0; k < group.size(); k++) {
            int g = group[k], p = profit[k];
            for (int i = P; i >= 0; i--)
                for (int j = G - g; j >= 0; j--)
                    dp[min(i + p, P)][j + g] = (dp[min(i + p, P)][j + g] + dp[i][j]) % mod;
        }
        for (int x: dp[P]) res = (res + x) % mod;
        return res;
    }
};