class Solution {
public:
    int solve(vector<int> prices, int index, bool purchased, bool coolDowned, vector<vector<int>> &dp){
        if(index == prices.size()) return 0;
        if(dp[index][purchased + 5 * coolDowned] != -1) return dp[index][purchased + 5 * coolDowned];
        int ans = 0;
        // not sell
        int notSold = solve(prices, index+1, purchased, true,dp);
        ans= max(notSold, ans);
        if(purchased){
            // sell 
            int sold = solve(prices, index+1, false, false,dp) + prices[index];
            ans = max(sold, notSold);
        }else if(coolDowned){
            // purchase
            int purchased = solve(prices, index+1, true, false,dp) - prices[index];
            ans = max(ans, purchased);
        }
        return dp[index][purchased + 5 * coolDowned] = ans;
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() , vector<int>(8, -1));
        return solve(prices, 0, false, true, dp);
    }
};