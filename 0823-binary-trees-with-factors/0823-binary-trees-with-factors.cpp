class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int ans = 0;
        map<int,int> mp;
        int mod = 1e9 + 7;
        for(int i = 0 ;i < arr.size(); i++){
            mp[arr[i]] = 1;
            for(int j = 0; j < i; j++){
                //if(arr[j] * arr[j] > arr[i]) break;
                int div = arr[i] / arr[j];
                if(arr[i] % arr[j] == 0 && arr[i] % div == 0){
                    int cur =  mp[arr[j]];
                     cur = ( (long long) cur * mp[div]) % mod;
                    mp[arr[i]] = (mp[arr[i]]  + cur ) % mod;
                }
            }
            ans =  (ans + mp[arr[i]]) % mod;
        }
        return ans;
    }
};