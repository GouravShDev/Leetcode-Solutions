class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        for(int i =0 ; i< nums.size()-1 ; i++){
            int diff = nums[i] - nums[i+1];
            for(int j = i + 1 ; j < nums.size()-1 ; j++){
                if(nums[j]- nums[j+1] == diff) ans++;
                else break;
            }
        }
        return ans;
    }
};