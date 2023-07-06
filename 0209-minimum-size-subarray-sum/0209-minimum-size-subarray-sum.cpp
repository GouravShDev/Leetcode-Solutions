class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int index = 0;
        int sum = 0;
        for(int i = 0;i < nums.size();i++){
            sum += nums[i];
            while(sum >= target && index <= i){
                ans = min(ans, i - index + 1);
                sum -= nums[index++];
            }
        }
        return ans == INT_MAX ? 0: ans;
    }
};