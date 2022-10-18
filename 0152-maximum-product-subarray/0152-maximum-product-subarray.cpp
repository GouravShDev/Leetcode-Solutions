class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int mnP = nums[0];
        int mxP = nums[0];
        int ans = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            int temp = mxP;
            mxP = max({nums[i], nums[i] * mxP, nums[i] * mnP});
            mnP = min({nums[i], temp * nums[i], nums[i] * mnP});
            ans = max({mxP, mnP, ans});
        }
        return ans;
    }
};