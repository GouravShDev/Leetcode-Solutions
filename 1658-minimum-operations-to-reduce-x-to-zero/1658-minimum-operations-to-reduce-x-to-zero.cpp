class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        int i = 0;
        int ans =-1 ;
        int curSum= 0;
        for(int  j = 0; j < nums.size(); j++){
            curSum+= nums[j];
            while(curSum > target && i <= j){
                curSum -= nums[i++];
            }
            if(curSum == target)
            ans = max(ans, j - i + 1);
        }
        return ans == -1 ? ans : nums.size() - ans;
    }
};