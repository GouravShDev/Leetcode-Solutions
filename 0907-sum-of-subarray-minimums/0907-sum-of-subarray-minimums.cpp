#define ll long long
class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n  = arr.size();
        vector<ll> prev(n,-1);
        vector<ll> next(n,n);
        stack<ll> stk;
        for(ll i =0 ;i < n; i++){
            while(!stk.empty() && arr[stk.top()] >= arr[i]){
                next[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        for(ll i =n-1;i >= 0; i--){
            while(!stk.empty() && arr[stk.top()] > arr[i]){
                prev[stk.top()] = i;
                stk.pop();
            }
            stk.push(i);
        }
        ll ans = 0;
        for(ll i =0;i < n ; i++){
            
            ll len = ((next[i]-i) % mod * (i - prev[i] ) % mod) % mod;
            // if(len < 0)
            ans += (arr[i]* len) % mod;
            // if(ans < 0){
                // cout<<ans;
            // }
        }
        return ans % mod;
    }
};