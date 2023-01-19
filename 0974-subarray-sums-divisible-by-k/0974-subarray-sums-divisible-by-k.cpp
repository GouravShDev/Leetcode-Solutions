class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum = 0;
        map<int,int> mp;
        mp[sum]++;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++){
            sum+= (nums[i]%k);
            sum%=k;
            if(sum<0)sum+=k;
            if(mp.count(sum)){
                ans += mp[sum];
            }
            mp[sum]++;
        }
        return ans;
    }
};