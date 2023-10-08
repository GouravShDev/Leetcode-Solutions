class Solution {
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int i , int j, bool isPicked, vector<vector<vector<int>>> &dp){
        if(i == nums1.size() || j == nums2.size()){
            return isPicked ? 0 : -1e6;
        }
        if(dp[i][j][isPicked] != -1e7) return dp[i][j][isPicked];
    
        int ans = nums1[i] * nums2[j] + solve(nums1, nums2, i + 1, j + 1, true, dp);
        // if(cur < 0) cur = 0;
    
        ans = max(ans , solve(nums1, nums2, i+1 ,j ,isPicked,dp));
        ans = max(ans, solve(nums1, nums2, i, j+1,isPicked,dp));
        return dp[i][j][isPicked] = ans;
        
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        
        vector<vector<vector<int>>> dp(nums1.size() , vector<vector<int>>(nums2.size(), vector<int>(2, -1e7)));
        return solve(nums1, nums2, 0 , 0, false, dp);
    }
};