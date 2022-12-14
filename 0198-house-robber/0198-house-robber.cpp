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
        vector<vector<int>> dp(nums.size() , vector<int>(2, -1));
        return solve(nums, 0, true, dp);
    }
};