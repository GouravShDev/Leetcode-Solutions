class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, int> mp;
        // mp[nums[0]] = -1;
        for(int i =0 ; i< nums.size(); i++){
            if(mp.count(nums[i]) && abs(mp[nums[i]]- i) <= k ){
                return true;
            }else{
                mp[nums[i]] = i;
            }
        }
        return false;
    }
};