class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int i = 0;
        int ans = 1;
        for(int j = 1; j < nums.size() ; j++){
            if(nums[j]- nums[j-1] <= 0){
                i = j;
            }
            ans = max(ans, j -i +1);
        }
        return ans;
    }
};