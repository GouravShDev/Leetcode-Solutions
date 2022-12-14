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
        int picked = 0;
        int notPicked = 0;
        for(int i  = n-1; i >= 0; i--){
            int ans =INT_MIN;
            // int lastPicked = picked;
            int lastNotPicked = notPicked;
            ans = max(ans, picked);
            notPicked = ans;
            ans =max(ans , nums[i] + lastNotPicked);
            picked = ans;
        }
        return picked ;
    }
};