class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int ans = 0;
        if(nums.size() < 2) return 0;
        int n = nums.size();
        for(int i =0 ;i < n-2; i++){
            int diff = nums[i+1]-nums[i];
            for(int j = i+1; j <n-1; j++){
                if(nums[j+1] - nums[j] == diff){ ans++;}
                else{
                    break;
                }
            }
        }
        return ans;
    }
};