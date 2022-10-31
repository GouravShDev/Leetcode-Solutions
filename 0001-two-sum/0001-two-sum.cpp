class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // we take map < nums[i] , i >
        map<int,int> mp;
        
        // we iterate over nums [i]
        for(int i= 0; i < nums.size(); i++){
            
            // cur nums[i]
            // requried nums = target - cur

            // required Num = 9 - 2 = 7
            int requiredNums = target - nums[i];
            // { 2 : 0 , }
            if(mp.find(requiredNums) != mp.end()){
                // if requiredNums present in map
                vector<int> ans({ mp[requiredNums], i });
                return ans;
            }
            mp[nums[i]] = i;
            
        } 
        return {};
    }
};