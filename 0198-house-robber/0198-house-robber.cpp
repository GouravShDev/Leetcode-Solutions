class Solution {
public:
    int solve(vector<int> &nums, int index, bool isAllowed, vector<vector<int>> &dp){
        if(index == nums.size()) return 0;
        int ans = INT_MIN;
        if(dp[index][isAllowed] != -1 )return dp[index][isAllowed];
        if(isAllowed){
            ans = max(ans, nums[index] + solve(nums, index+1, false, dp));
        }
        ans = max(ans , solve(nums, index+1, true, dp));
        return dp[index][isAllowed] = ans;
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(nums.size()+1 , vector<int>(2));
        for(int i  = n-1; i >= 0; i--){
            int ans =INT_MIN;
            ans = max(ans, dp[i+1][1]);
            dp[i][0] = ans;
            ans =max(ans , nums[i] + dp[i+1][0]);
            dp[i][1] = ans;
        }
        return dp[0][1] ;
    }
};