class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
      vector<int> ans;
        for(int i =0 ;i < nums.size() ; i++){
            int value = abs(nums[i])-1;
            if(nums[value] < 0){
                ans.push_back(value+1);
            }else{
                nums[value] = -nums[value];
            }
        }
        for(int i= 0; i < nums.size() ; i++){
            if(nums[i] > 0){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};