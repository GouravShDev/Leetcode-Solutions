class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int ans= 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[i] == 0){
                // if(firstEncounter){
                //     firstEncounter = false;
                // }else{
                //     firstEncounter = true;
                    left = right;
                    right = 0;
                // }
                
                continue;
            }
            right++;
                ans = max(ans, left + right);
            
        }
        if(ans == nums.size()) return ans-1;
        return ans;
    }
};