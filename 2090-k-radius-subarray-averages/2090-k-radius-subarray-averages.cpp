class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans(nums.size(),-1);
        if(k == 0) return nums;
        long long curSum = 0;
        int curNum = 0;
         // cout<<nums.size()-(k-1);
        for(int i =0 ; i < (int) nums.size(); i++){
          
            curSum += nums[i];
            curNum++;
            if(curNum < (2 * k + 1)){
                continue;
            }else if(curNum > (2 * k + 1)){
                curSum -= nums[i - (2 * k + 1)];
                curNum--;
            }
            
            if(curNum > 0)ans[i - k] = (curSum/curNum);
            
        }
        return ans;
    }
};