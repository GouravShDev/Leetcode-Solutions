#define ll long long
class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pref(n);
        pref[0] = nums[0];
        for(int i = 1; i < n ; i++){
            pref[i] += pref[i-1] + nums[i];
        }
        ll sum = pref[n-1];
        int minAvg  = INT_MAX;
        int ans = 0;
        for(int i = 0 ; i < n; i++){
            ll leftAvg = pref[i] / (i + 1);
            ll rightAvg = (i == n-1) ? 0 : (sum - pref[i])/ (n - i - 1);
            if(minAvg > abs(leftAvg - rightAvg)){
                minAvg = abs(leftAvg- rightAvg);
                ans = i;
            }
        }
        return ans;
    }
};