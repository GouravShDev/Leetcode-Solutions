class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        map<int,int> mp;
        for(auto &num : nums){
            mp[num % space]++;
        }
        int ans = *max_element(nums.begin() , nums.end(), [&] (int &n1, int &n2){
           int modN1 = mp[n1 % space];
            int modN2 = mp[n2 % space];
            return modN1 == modN2 ? n1 > n2 : modN1 <modN2;
        });
        return ans;
    }
};