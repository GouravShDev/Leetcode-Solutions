class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        while(i < nums.size()-1){
            if(nums[i] == nums[i+1] && nums[i+1] == nums[i+2]){
                i+= 3;
            }else{
                return nums[i];
            }
            
        }
        return nums[nums.size()-1];
    }
};