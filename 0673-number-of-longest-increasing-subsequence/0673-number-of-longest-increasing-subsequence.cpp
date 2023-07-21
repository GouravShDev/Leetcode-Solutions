class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1); // length;
        vector<int> count(nums.size(), 1); // count;
        int maxLength = 1;
        for(int i = 0 ; i < nums.size();i ++){
            for(int j = 0 ; j < i; j++){
                if(nums[i] > nums[j]){
                if(dp[j] + 1 == dp[i]){
                    count[i] += count[j];
                }else if(dp[j] + 1 > dp[i]){
                    count[i] = count[j];
                    dp[i] = 1 + dp[j];
                    maxLength = max(maxLength , dp[i]);
                }
                }
            }
        }
        int ans =0 ;
        for(int i = 0 ; i < nums.size(); i++){
            if(dp[i] == maxLength ) ans+=count[i];
        }
        return ans;
    }
};