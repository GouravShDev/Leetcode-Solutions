class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> mp(33);
        for(auto &num : nums){
            if(num < 0) mp[32]++;
            long long x = abs(num);
            for(int i = 0; i < 32 ; i++){
                int mask = 1 << i;
                if((x & mask) > 0){
                    mp[i]++;
                }
            }
        }
        // 30th bit
        long long ans = 0;
        for(int i =0 ;i < 32; i++){
            int it =  mp[i];
            it = it % 3;
            // cout<<it<<" ";
            if(it)
                ans |= (1 << i);
        }
        if(mp[32] % 3){
            return -ans;
        }
        return ans;
    }
};